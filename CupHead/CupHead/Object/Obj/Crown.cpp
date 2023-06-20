#include "framework.h"
#include "Crown.h"

Crown::Crown()
{
	_main_col = make_shared<CircleCollider>(80);
	_main_trans = make_shared<Transform>();

	_second_col = make_shared<CircleCollider>(70);
	_second_trans = make_shared<Transform>();

	_fBuffer = make_shared<FilterBuffer>();

	_main_trans->SetParent(_main_col->GetTransform());
	_second_trans->SetParent(_second_col->GetTransform());

	_main_trans->SetPos(Vector2(10,20));

	CreateAction("Clown_Intro_Idle", 0.5, 0.05, Action::Type::END);
	CreateAction("Clown_Intro_1", 0.5, 0.05, Action::Type::END);
	CreateAction("Clown_Intro_2",0.5, 0.05, Action::Type::END);
	CreateAction("Clown_Move_1",0.5, 0.05, Action::Type::END);
	CreateAction("Clown_Move_Break_1",0.5, 0.05, Action::Type::END);
	CreateAction("Clown_Move_2",0.5, 0.05, Action::Type::END);
	CreateAction("Clown_Move_Break_2",0.5, 0.05, Action::Type::END);
	CreateAction("Clown_Move_3",0.5, 0.05, Action::Type::END);
	CreateAction("Page_Two_Intro_1",0.5, 0.1, Action::Type::END);
	CreateAction("Page_Two_Intro_2",0.5, 0.1, Action::Type::END);
	CreateAction("Page_Two_Body_Idle",0.5, 0.1, Action::Type::LOOP);
	CreateAction("Clown_Page_Two_Intro",0.5, 0.1, Action::Type::END);
	CreateAction("Clown_Page_Two_Idle",0.5, 0.1, Action::Type::LOOP);

	Init_Stage1();

	_actions[Action_State::INTRO_IDLE]->Play();

	for (int i = 0; i < 50; i++)
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>("Bullet", 20);
		bullet->SetSpeed(300);
		_bullets.push_back(bullet);
	}
}

void Crown::Update()
{
	if (_isDisable)
		return;

	else if (_hp <= 0.0)
	{
		_fBuffer->_data.type = 1;
		if (_fBuffer->_data.val2 < 70)
			_fBuffer->_data.val2++;
		else
			_isDisable = true;
		_fBuffer->Update_Resource();
		return;
	}

	if (_redTimer > 0)
		_redTimer -= DELTA_TIME;
	

	_main_col->Update();
	_main_trans->Update();

	if (_stopTimer > 0.0)
	{
		_stopTimer -= DELTA_TIME;
		_shootTimer -= DELTA_TIME;

		if (_shootTimer < 0.0)
		{
			Shoot();
			_shootTimer = 1;
		}
	}
	else if (_stopTimer < 0.0 && !_actions[_mainIndex]->IsPlaying())
	{
		SetAction(_nextIndex);
	}
	
	if (_stage == 0 && _actions[_mainIndex]->IsPlaying())
	{
		Move();

		if (_isLeft)
			_main_trans->SetPos(Vector2(20, 20));
		else
			_main_trans->SetPos(Vector2(-20, 20));
	}

	_actions[_mainIndex]->Update();

	_sprites[_mainIndex]->SetCurClip(_actions[_mainIndex]->GetCurClip());
	
	if (_isLeft)
		_sprites[_mainIndex]->SetRight();
	else
		_sprites[_mainIndex]->SetLeft();

	_sprites[_mainIndex]->Update();

	if (_stage == 1)
	{
		_second_col->Update();
		_second_trans->Update();

		_sprites[_secondState]->SetCurClip(_actions[_secondState]->GetCurClip());
		_sprites[_secondState]->Update();
	}

	for (shared_ptr<Bullet> bullet : _bullets)
	{
		bullet->Update();
	}

	_fBuffer->SetImageSize(_sprites[_mainIndex]->GetClipSize());
	_fBuffer->Update_Resource();
}

void Crown::Render()
{
	if (_isDisable)
		return;
	_main_trans->Set_World(0);
	_fBuffer->SetPS_Buffer(2);
	_sprites[_mainIndex]->Render();

	_main_col->Render();
	
	if (_stage == 1)
	{
		_second_trans->Set_World(0);
		_sprites[_secondState]->Render();

		_second_col->Render();
	}

	for (shared_ptr<Bullet> bullet : _bullets)
	{
		bullet->Render();
	}
}

void Crown::PostRender()
{
	ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[0]);
	ImGui::SetWindowFontScale(1.2f);
	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));

	ImGui::Text("Crown");

	ImGui::PopFont();
	ImGui::PopStyleColor();
	ImGui::SetWindowFontScale(1.0f);

	ImGui::SliderInt("Crown_HP", (int*)&_hp, 0, 100);
	ImGui::SliderInt("Crown_State", (int*)&_mainIndex, 0, 16);
	ImGui::Checkbox("Crown_Disable", (bool*)&_isDisable);

	ImGui::SliderInt("selected", &_fBuffer->_data.type, 0, 5);
	ImGui::SliderInt("value1", &_fBuffer->_data.val1, 0, 300);
	ImGui::SliderInt("value2", &_fBuffer->_data.val2, 0, 300);
	ImGui::SliderInt("value3", &_fBuffer->_data.val3, 0, 300);
}

void Crown::GetDamage(int amount)
{
	_hp -= amount;

	if (_hp <= 90)
	{
		NextStage();
	}
}

void Crown::Init_Stage1()
{
	_actions[Action_State::INTRO_IDLE]->SetStartEventBool(std::bind(&Crown::SetDisable, this, true));
	_actions[Action_State::INTRO_2]->SetEndEventBool(std::bind(&Crown::SetDisable, this, false));

	_actions[Action_State::INTRO_IDLE]->SetEndEventInt(std::bind(&Crown::NextIndex, this, 1));
	_actions[Action_State::INTRO_1]->SetEndEventInt(std::bind(&Crown::NextIndex, this, 2));
	_actions[Action_State::INTRO_2]->SetEndEventInt(std::bind(&Crown::NextIndex, this, 3));

	_actions[Action_State::MOVE_1]->SetEndEventInt(std::bind(&Crown::NextIndex, this, 4));
	_actions[Action_State::MOVE_BREAK_1]->SetEndEventDI(std::bind(&Crown::MoveDelay, this, 1, 5));
	_actions[Action_State::MOVE_2]->SetEndEventInt(std::bind(&Crown::NextIndex, this, 6));
	_actions[Action_State::MOVE_BREAK_2]->SetEndEventDI(std::bind(&Crown::MoveDelay, this, 1, 7));
	_actions[Action_State::MOVE_3]->SetEndEventInt(std::bind(&Crown::NextIndex, this, 3));
}

void Crown::Init_Stage2()
{

}

void Crown::NextStage()
{

}

void Crown::CreateAction(string name, float scale, float speed, Action::Type type, CallBack callBack)
{
	wstring wName = wstring(name.begin(), name.end());
	wstring srvPath = L"Resource/Boss/" + wName + L".png";
	shared_ptr<SRV> srv = ADD_SRV(srvPath);

	string xmlPath = "Resource/Boss/" + name + ".xml";
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

	shared_ptr<Sprite> sprite = make_shared<Sprite>(srvPath, Vector2(averageW / count * scale, averageH / count * scale));
	_sprites.push_back(sprite);
}
void Crown::Shoot()
{
	if (_mainCharacter.expired() == false)
	{
		for (shared_ptr<Bullet> bullet : _bullets)
	{
		if (!bullet->IsActive())
		{				
			Vector2 dir = _mainCharacter.lock()->GetCollider()->GetWorldPos() - _main_col->GetWorldPos();
			dir.Normalize();
			bullet->Shoot(_main_col->GetWorldPos(), dir);
			break;
		}
	}
	}
}
void Crown::SetAction(int state)
{
	if (_mainIndex == state)
		return;

	_actions[_mainIndex]->Reset();
	_actions[_mainIndex]->Pause();

	_mainIndex = state;
	_actions[_mainIndex]->Play();
}

void Crown::MoveDelay(double timer, int index)
{
	_stopTimer = timer;
	_nextIndex = index;
}

void Crown::Move()
{
	if (_mainIndex <= 2 || _mainIndex >= 8)
		return;

	if (_isLeft)
	{
		_main_col->AddPos(-RIGHT_VECTOR * DELTA_TIME * 400.0f);
	}
	else
	{
		_main_col->AddPos(RIGHT_VECTOR * DELTA_TIME * 400.0f);
	}

	Vector2 wPos = _main_col->GetWorldPos();

	if (wPos.x <= 0)
	{
		_isLeft = false;
	}
	else if (wPos.x >= WIN_WIDTH)
	{
		_isLeft = true;
	}
}

void Crown::SetAction(Action_State state)
{
	if (_mainState == state)
		return;

	_actions[_mainState]->Reset();
	_actions[_mainState]->Pause();

	_mainState = state;
	_actions[_mainState]->Play();
}
