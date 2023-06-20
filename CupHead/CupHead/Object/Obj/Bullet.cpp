#include "framework.h"
#include "Bullet.h"

Bullet::Bullet(string path, float size)
{
	_col = make_shared<CircleCollider>(size);
	_transform = make_shared<Transform>();

	_col->SetPos(CENTER - Vector2(WIN_WIDTH/2, 0));
	_col->SetAngle(-90 * PI / 180);

	_transform->SetPos(Vector2(0, -60));
	_transform->SetParent(_col->GetTransform());

	CreateAction(path + "_Intro", 0.1, Action::Type::END, std::bind(&Bullet::ToLoop, this));
	CreateAction(path + "_Loop", 0.07, Action::Type::LOOP, std::bind(&Bullet::ToEnd, this));
	CreateAction(path + "_End", 0.07, Action::Type::LOOP, std::bind(&Bullet::ToFinish, this));

	_actions[State::INTRO]->Play();
}

void Bullet::Update()
{
	if (!_isActive)
		return;
	
	_curTime += DELTA_TIME;

	if (_curTime > _lifeTime)
	{
		_isActive = false;
		_curTime = 0.0f;
	}
	
	_col->AddPos(_dir * DELTA_TIME * _speed);
	
	_transform->Update();
	_col->Update();
	_actions[_state]->Update();

	_sprites[_state]->SetCurClip(_actions[_state]->GetCurClip());
	_sprites[_state]->Update();
}

void Bullet::Render()
{
	if (!_isActive)
		return;

	_transform->Set_World(0);
	_sprites[_state]->Render();

	_col->Render();
}

void Bullet::Shoot(Vector2 pos, Vector2 dir)
{
	_isActive = true;
	_state = State::INTRO;
	_actions[_state]->Play();

	_col->SetPos(pos);
	_col->SetAngle(dir.Angle() - 90 * PI / 180.0f);
	_dir = dir;
}

void Bullet::CreateAction(string name, float speed, Action::Type type, CallBack callBack)
{
	wstring wName = wstring(name.begin(), name.end());
	wstring srvPath = L"Resource/Bullet/" + wName + L".png";
	shared_ptr<SRV> srv = ADD_SRV(srvPath);

	if (srv->GetImageSize().x == 0 && srv->GetImageSize().y == 0) return;

	string xmlPath = "Resource/Bullet/" + name + ".xml";
	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	document->LoadFile(xmlPath.c_str());

	tinyxml2::XMLElement* textureAtlas = document->FirstChildElement();
	tinyxml2::XMLElement* row = textureAtlas->FirstChildElement();

	vector<Action::Clip> clips;
	float averageW = 0;
	float averageH = 0;
	int count = 0;

	while (true)
	{
		if (row == nullptr)
			break;

		int x = row->FindAttribute("x")->IntValue();
		int y = row->FindAttribute("y")->IntValue();
		int w = row->FindAttribute("w")->IntValue();
		int h = row->FindAttribute("h")->IntValue();

		averageW += w;
		averageH += h;
		count++;

		Action::Clip clip = Action::Clip(x, y, w, h, srv);
		clips.push_back(clip);

		row = row->NextSiblingElement();
	}

	shared_ptr<Action> action = make_shared<Action>(clips, name, type, speed);
	action->SetEndEvent(callBack);

	_actions.push_back(action);

	shared_ptr<Sprite> sprite = make_shared<Sprite>(srvPath, Vector2(averageW / count, averageH / count));
	_sprites.push_back(sprite);
}

void Bullet::ToLoop()
{
	_actions[_state]->Reset();
	_actions[_state]->Pause();

	_state = State::LOOP;
	_actions[_state]->Play();
}

void Bullet::ToEnd()
{
	if (_actions.size() == 2)
	{
		_isActive = false;
		return;
	}
	_actions[_state]->Reset();
	_actions[_state]->Pause();

	_state = State::END;
	_actions[_state]->Play();
}

void Bullet::ToFinish()
{
	_actions[_state]->Reset();
	_actions[_state]->Pause();
	_isActive = false;
}
