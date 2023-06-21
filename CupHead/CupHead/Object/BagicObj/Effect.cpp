#include "framework.h"
#include "Effect.h"

Effect::Effect(string name, Vector2 size, float speed, Action::Type type)
{
	_transform = make_shared<Transform>();
	CreateAction(name, speed, type);
	CreateAction(name+"_Intro", speed, type);
	CreateAction(name+"_Loop", speed, type);
	CreateAction(name+"_End", speed, type);
	_actions[0]->Play();
}

void Effect::Render()
{
	if (!_isActive)
		return;

	_transform->Set_World(0);
	_sprites[_curClip]->Render();
}

void Effect::Update()
{
	if (!_isActive)
		return;
	_transform->Update();
	_actions[_curClip]->Update();

	_sprites[_curClip]->SetCurClip(_actions[_curClip]->GetCurClip());
	_sprites[_curClip]->Update();
}

void Effect::Play(Vector2 pos)
{
	_transform->SetPos(pos);
	_isActive = true;
	_curClip = 0;
	_actions[_curClip]->Play();
}

void Effect::CreateAction(string name, float speed, Action::Type type, CallBack callBack)
{
	wstring wName = wstring(name.begin(), name.end());
	wstring srvPath = L"Resource/Effect/" + wName + L".png";
	weak_ptr<SRV> srv = ADD_SRV(srvPath);
	Vector2 size = srv.lock()->GetImageSize();
	if (size.x == 0 && size.y == 0)
		return;

	string xmlPath = "Resource/Effect/" + name + ".xml";
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

		Action::Clip clip = Action::Clip(x, y, w, h, srv.lock());
		clips.push_back(clip);

		row = row->NextSiblingElement();
	}

	shared_ptr<Action> action = make_shared<Action>(clips, name, type, speed);
	action->SetEndEvent(std::bind(&Effect::EndEvent, this));

	_actions.push_back(action);

	shared_ptr<Sprite> sprite = make_shared<Sprite>(srvPath, Vector2(averageW / count, averageH / count));
	_sprites.push_back(sprite);
}

void Effect::EndEvent()
{
	if (_actions.size() - 1 <= _curClip)
		_isActive = false;
	else
	{
		_curClip++;
		_actions[_curClip]->Play();
	}
}
