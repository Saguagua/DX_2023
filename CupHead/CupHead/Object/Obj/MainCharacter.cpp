#include "framework.h"
#include "MainCharacter.h"

MainCharacter::MainCharacter()
{
	_col = make_shared<CircleCollider>(50);
	_col->GetTransform()->SetScale(Vector2(0.7f, 0.7f));
	_transform = make_shared<Transform>();
	_bulletSlot = make_shared<Transform>();

	_col->GetTransform()->SetPos(CENTER);

	_transform->SetParent(_col->GetTransform());
	_transform->SetPos(Vector2(0, 20));

	_bulletSlot->SetPos(Vector2(20,0));
	_bulletSlot->SetParent(_col->GetTransform());

	CallBack SetAim = std::bind(&MainCharacter::SetAim, this);
	CallBack SetIdle = std::bind(&MainCharacter::SetIdle, this);

	CreateAction("Idle", 0.06f, Action::Type::PINGPONG);
	CreateAction("Run", 0.07f);
	CreateAction("Jump", 0.07f);
	CreateAction("Duck", 0.07f, Action::Type::END, SetIdle);
	CreateAction("DuckIdle", 0.07f, Action::Type::LOOP);
	CreateAction("AimStraightShot", 0.05f, Action::Type::END, SetAim);
	CreateAction("AimUpShot", 0.05f, Action::Type::END, SetAim);
	CreateAction("AimDownShot", 0.05f, Action::Type::END, SetAim);
	CreateAction("AimDiagonalUpShot", 0.05f, Action::Type::END, SetAim);
	CreateAction("AimDiagonalDownShot", 0.05f, Action::Type::END, SetAim);
	CreateAction("RunShot", 0.05f, Action::Type::END, SetIdle);
	CreateAction("DuckShot", 0.05f, Action::Type::END, SetIdle);
	CreateAction("AimStraight", 0.08f, Action::Type::LOOP);
	CreateAction("AimUp", 0.08f, Action::Type::LOOP);
	CreateAction("AimDown", 0.08f, Action::Type::LOOP);
	CreateAction("AimDiagonalUp", 0.08f, Action::Type::LOOP);
	CreateAction("AimDiagonalDown", 0.08f, Action::Type::LOOP);

	_actions[Action_State::IDLE_ACTION]->Play();

	for (int i = 0; i < 50; i++)
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>("Bullet", 20);
		_bullets.push_back(bullet);
	}
}

void MainCharacter::Update()
{
	Input();

	if (_bitFlag & Player_State::ONAIR_PLAYER)
	{
		_jumpDuration -= DELTA_TIME;

		if (_jumpDuration > 0)
		{
			_col->GetTransform()->AddPos(UP_VECTOR * DELTA_TIME * _jumpSpeed);
		}
		else
		{
			_col->GetTransform()->AddPos(-UP_VECTOR * DELTA_TIME * GRAVITY);
		}
	}

	_col->Update();
	_transform->Update();

	_actions[_state]->Update();

	_sprites[_state]->SetCurClip(_actions[_state]->GetCurClip());
	_sprites[_state]->Update();

	for (shared_ptr<Bullet> bullet : _bullets)
	{
		bullet->Update();
	}
}

void MainCharacter::Render()
{
	_transform->Set_World(0);
	_sprites[_state]->Render();

	_col->Render();

	for (shared_ptr<Bullet> bullet : _bullets)
	{
		bullet->Render();
	}
}

void MainCharacter::PostRender()
{
	ImGui::SliderInt("State", (int*)&_state, 0, 16);
	ImGui::SliderInt("BitFlag", (int*)&_bitFlag, 0, 63);
	ImGui::SliderFloat("DirectionX", (float*)&_dir.x, -1, 1);
	ImGui::SliderFloat("DirectionY", (float*)&_dir.y, -1, 1);
}

void MainCharacter::Input()
{

	if (KEY_PRESS(VK_UP))
	{
		_dir.y = 1;
	}
	else if (KEY_UP(VK_UP))
	{
		_dir.y = 0;
	}

#pragma region left_right
	//left
	if (KEY_UP(VK_LEFT))
	{
		if (_bitFlag & Player_State::LOCK_PLAYER)
		{
			_dir.x = 0;
		}
		else if (!KEY_DOWN(VK_RIGHT) && !KEY_PRESS(VK_RIGHT))
		{
			if (!(_bitFlag & Player_State::ONAIR_PLAYER))
			{
				SetAction(Action_State::IDLE_ACTION);
			}
			_sprites[_state]->SetLeft();

			_bitFlag = _bitFlag & (~Player_State::RUN_PLAYER);
		}		
	}
	else if (KEY_DOWN(VK_LEFT))
	{
		if (_bitFlag & Player_State::LOCK_PLAYER)
		{
			_dir.x = -1;
		}
		else
		{
			if (!(_bitFlag & Player_State::ONAIR_PLAYER))
			{
				SetAction(Action_State::RUN_ACTION);
			}
			_bitFlag = _bitFlag | Player_State::RUN_PLAYER;
			_col->GetTransform()->AddPos(-RIGHT_VECTOR * DELTA_TIME * _moveSpeed);
			_sprites[_state]->SetLeft();
		}
		
	}
	else if (KEY_PRESS(VK_LEFT))
	{
		if (_bitFlag & Player_State::LOCK_PLAYER)
		{
			_dir.x = -1;
		}
		else
		{
			if (!(_bitFlag & Player_State::ONAIR_PLAYER) && !(_bitFlag & Player_State::ATTACK_PLAYER))
			{
				SetAction(Action_State::RUN_ACTION);
				_bitFlag = _bitFlag | Player_State::RUN_PLAYER;
			}
			_col->GetTransform()->AddPos(-RIGHT_VECTOR * DELTA_TIME * _moveSpeed);
			_sprites[_state]->SetLeft();
		}
	}
	//right
	if (KEY_UP(VK_RIGHT))
	{
		if (_bitFlag & Player_State::LOCK_PLAYER)
		{
			_dir.x = 0;
		}
		else if(!KEY_DOWN(VK_LEFT) && !KEY_PRESS(VK_LEFT))
		{
			if (!(_bitFlag & Player_State::ONAIR_PLAYER))
			{
				SetAction(Action_State::IDLE_ACTION);
			}
			_sprites[_state]->SetRight();

			_bitFlag = _bitFlag & (~Player_State::RUN_PLAYER);
		}
	}
	else if (KEY_DOWN(VK_RIGHT))
	{
		if (_bitFlag & Player_State::LOCK_PLAYER)
		{
			_dir.x = 1;
		}
		else
		{
			if (!(_bitFlag & Player_State::ONAIR_PLAYER))
			{
				SetAction(Action_State::RUN_ACTION);
			}
			_bitFlag = _bitFlag | Player_State::RUN_PLAYER;

			_col->GetTransform()->AddPos(RIGHT_VECTOR * DELTA_TIME * _moveSpeed);
			_sprites[_state]->SetRight();
		}
	
	}
	else if (KEY_PRESS(VK_RIGHT))
	{
		if (_bitFlag & Player_State::LOCK_PLAYER)
		{
			_dir.x = 1;
		}
		else
		{
			if (!(_bitFlag & Player_State::ONAIR_PLAYER) && !(_bitFlag & Player_State::ATTACK_PLAYER))
			{
				SetAction(Action_State::RUN_ACTION);
				_bitFlag = _bitFlag | Player_State::RUN_PLAYER;
			}
			_col->GetTransform()->AddPos(RIGHT_VECTOR * DELTA_TIME * _moveSpeed);
			_sprites[_state]->SetRight();
		}		
	}
#pragma endregion

#pragma region down
	//down
	if (KEY_DOWN(VK_DOWN))
	{
		if (_bitFlag & Player_State::LOCK_PLAYER)
		{
			_dir.y = -1;
		}
		else
		{
			_bitFlag = _bitFlag | Player_State::DOWN_PLAYER;
			int front = _sprites[_state]->GetFront();
			SetAction(Action_State::DOWN_ACTION);
			_sprites[_state]->SetFront(front);
			_actions[_state]->SetReverse(false);
		}
	}
	else if (KEY_UP(VK_DOWN))
	{
		if (_bitFlag & Player_State::LOCK_PLAYER)
		{
			_dir.y = 0;
		}
		else
		{
			_bitFlag = _bitFlag & (~Player_State::DOWN_PLAYER);
			int front = _sprites[_state]->GetFront();
			SetAction(Action_State::IDLE_ACTION);
			_sprites[_state]->SetFront(front);
		}
		
	}
#pragma endregion

#pragma region shoot
	if (KEY_DOWN('X'))
	{
		if (_bitFlag & Player_State::LOCK_PLAYER)
		{
			if (_dir.x == -1 && _dir.y == -1)
			{
				Fire(_col->GetWorldPos(), _dir, Action_State::ATTACK_DIAGONAL_DOWN_ACTION, 1);
			}
			else if (_dir.x == -1 && _dir.y == 0)
			{
				Fire(_col->GetWorldPos(), _dir, Action_State::ATTACK_FRONT_ACTION, 1);
			}
			else if (_dir.x == -1 && _dir.y == 1)
			{
				Fire(_col->GetWorldPos(), _dir, Action_State::ATTACK_DIAGONAL_UP_ACTION, 1);
			}
			if (_dir.x == 0 && _dir.y == -1)
			{
				int front = _sprites[_state]->GetFront();
				Fire(_col->GetWorldPos(), _dir, Action_State::ATTACK_DOWN_ACTION, front);
			}
			else if (_dir.x == 0 && _dir.y == 0)
			{
				int front = _sprites[_state]->GetFront();

				if (front == 0)
					_dir.x = 1;
				else
					_dir.x = -1;

				Fire(_col->GetWorldPos(), _dir, Action_State::ATTACK_FRONT_ACTION, front);
			}
			else if (_dir.x == 0 && _dir.y == 1)
			{

				Fire(_col->GetWorldPos(), _dir, Action_State::ATTACK_UP_ACTION, _sprites[_state]->GetFront());
			}
			if (_dir.x == 1 && _dir.y == -1)
			{
				Fire(_col->GetWorldPos(), _dir, Action_State::ATTACK_DIAGONAL_DOWN_ACTION, 0);
			}
			else if (_dir.x == 1 && _dir.y == 0)
			{
				Fire(_col->GetWorldPos(), _dir, Action_State::ATTACK_FRONT_ACTION, 0);
			}
			else if (_dir.x == 1 && _dir.y == 1)
			{
				Fire(_col->GetWorldPos(), _dir, Action_State::ATTACK_DIAGONAL_UP_ACTION, 0);
			}

		}
		else if (_bitFlag & Player_State::RUN_PLAYER)
		{
			_bitFlag = _bitFlag | Player_State::ATTACK_PLAYER;
			int front = _sprites[_state]->GetFront();
			if (front == 0)
				_dir.x = 1;
			else
				_dir.x = -1;
			Fire(_col->GetWorldPos(), _dir, Action_State::ATTACK_RUN_ACTION, front);
		}
		else if (_bitFlag & Player_State::DOWN_PLAYER)
		{
			_bitFlag = _bitFlag | Player_State::ATTACK_PLAYER;
			int front = _sprites[_state]->GetFront();
			if (front == 0)
				_dir.x = 1;
			else
				_dir.x = -1;
			Fire(_col->GetWorldPos() - Vector2(0, 30), _dir, Action_State::ATTACK_DUCK_ACTION, front);
		}
		else if (_bitFlag & Player_State::ONAIR_PLAYER)
		{
			int front = _sprites[_state]->GetFront();

			if (front == 0)
				_dir.x = 1;
			else
				_dir.x = -1;
			Fire(_col->GetWorldPos(), _dir, Action_State::JUMP_ACTION, front);
		}
		else
		{
			int front = _sprites[_state]->GetFront();

			if (front == 0)
				_dir.x = 1;
			else
				_dir.x = -1;
			Fire(_col->GetWorldPos(), _dir, Action_State::ATTACK_FRONT_ACTION, front);
		}
		
	}
#pragma endregion

#pragma region lock
	//lock
	if (KEY_DOWN('C'))
	{
		_bitFlag = _bitFlag | Player_State::LOCK_PLAYER;
		SetAction(Action_State::IDLE_ACTION);
		_dir.x = 0;
		_dir.y = 0;
	}
	else if (KEY_UP('C'))
	{
		_bitFlag = _bitFlag & ~Player_State::LOCK_PLAYER;
		_dir.x = 0;
		_dir.y = 0;
	}

#pragma endregion

#pragma region jump
	if (KEY_DOWN('Z') && !(_bitFlag & Player_State::ONAIR_PLAYER))
	{
		_spaceDown = true;
 		_jumpDuration = RUN_TIME;
	}
	else if (KEY_UP('Z') && !(_bitFlag & Player_State::ONAIR_PLAYER))
	{
		_spaceDown = false;
		_jumpDuration = (RUN_TIME - _jumpDuration);
		if (_jumpDuration > 0.25)
		{
			_jumpDuration = 0.5;
		}
		else
			_jumpDuration = 0.3;

		SetAction(Action_State::JUMP_ACTION);
		_bitFlag = _bitFlag | Player_State::ONAIR_PLAYER;
	}
#pragma endregion
}

void MainCharacter::SetIdle()
{
	_actions[_state]->Reset();
	_actions[_state]->Pause();

	int front = _sprites[_state]->GetFront();

	switch (_state)
	{
	case Action_State::DOWN_ACTION:
	{
		_state = Action_State::DOWNIDLE_ACTION;
		break;
	}
	case Action_State::ATTACK_RUN_ACTION:
	{
		_state = Action_State::RUN_ACTION;
		FireEnd();
		break;
	}
	case Action_State::ATTACK_DUCK_ACTION:
	{
		_state = Action_State::DOWNIDLE_ACTION;
		FireEnd();
		break;
	}
	default:
		_state = Action_State::IDLE_ACTION;
	}

	_sprites[_state]->SetFront(front);

	_actions[_state]->Play();
}

void MainCharacter::SetAim()
{
	int front = _sprites[_state]->GetFront();
	_actions[_state]->Reset();
	_actions[_state]->Pause();
	
	switch (_state)
	{
	case Action_State::ATTACK_FRONT_ACTION:
	{
		_state = Action_State::AIM_FRONT_ACTION;
		break;
	}
	case Action_State::ATTACK_UP_ACTION:
	{
		_state = Action_State::AIM_UP_ACTION;
		break;
	}
	case Action_State::ATTACK_DOWN_ACTION:
	{
		_state = Action_State::AIM_DOWN_ACTION;
		break;
	}
	case Action_State::ATTACK_DIAGONAL_UP_ACTION:
	{
		_state = Action_State::AIM_DIAGONAL_UP_ACTION;
		break;
	}
	case Action_State::ATTACK_DIAGONAL_DOWN_ACTION:
	{
		_state = Action_State::AIM_DIAGONAL_DOWN_ACTION;
		break;
	}
	}

	_sprites[_state]->SetFront(front);
	_actions[_state]->Play();
	FireEnd();
}

void MainCharacter::Fire(Vector2 pos, Vector2 dir, Action_State state, int front)
{
	for (shared_ptr<Bullet> bullet : _bullets)
	{
		if (!bullet->IsActive())
		{
			int num = rand() % 2 + 1;
			if (front == 1)
			{

				bullet->Shoot(pos - Vector2(20, -num * 10), dir);
				SetAction(state);
				_sprites[_state]->SetLeft();
			}
			else
			{
				bullet->Shoot(pos + Vector2(20, num * 10), dir);
				SetAction(state);
				_sprites[_state]->SetRight();
			}

			break;
		}
	}
}

void MainCharacter::FireEnd()
{
	_bitFlag = _bitFlag & (~Player_State::ATTACK_PLAYER);
}

void MainCharacter::GetDamage(int amount)
{
	_hp -= amount;

	if (_hp <= 0)
	{

	}
}

void MainCharacter::CreateAction(string name, float speed, Action::Type type, CallBack callBack)
{
	wstring wName = wstring(name.begin(), name.end());
	wstring srvPath = L"Resource/MainCharacter/" + wName + L".png";
	shared_ptr<SRV> srv = ADD_SRV(srvPath);

	string xmlPath = "Resource/MainCharacter/" + name + ".xml";
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

void MainCharacter::SetAction(Action_State state, bool reverse)
{
	if (_state == state)
		return;

	_actions[_state]->Reset();
	_actions[_state]->Pause();

	_state = state;
	_actions[_state]->SetReverse(reverse);
	_actions[_state]->Play();
}

void MainCharacter::SetOnGround()
{
	_bitFlag = _bitFlag & (~Player_State::ONAIR_PLAYER);
	if (_state == Action_State::JUMP_ACTION)
	{
		if (_bitFlag & Player_State::RUN_PLAYER)
			SetAction(Action_State::RUN_ACTION);
		else
			SetAction(Action_State::IDLE_ACTION);
	}
}

void MainCharacter::SetOnAir()
{
	_bitFlag = _bitFlag | Player_State::ONAIR_PLAYER;
	SetAction(Action_State::JUMP_ACTION);
}
