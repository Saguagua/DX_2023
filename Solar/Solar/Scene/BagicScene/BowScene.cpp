#include "framework.h"
#include "BowScene.h"

BowScene::BowScene()
{
	_player = make_shared<Character>(L"Player");
	_bullet = _player->GetBullets();
	_sun = make_shared<Planet>(L"sun");

	_sun->SetScale(Vector2(0.1f, 0.1f));
	_object = make_shared<CircleCollider>(80.0f);
	_object->SetPos(CENTER);
}

BowScene::~BowScene()
{
}

void BowScene::Update()
{
	if (_object->IsRed() && _timer + 0.1 < RUN_TIME)
	{
		_object->SetColor(GREEN);
	}
	_sun->SetPosition(MOUSE_POS);
	_player->Update();
	_sun->Update();
	_object->Update();

	for (auto bullet : _bullet)
	{
		if (!bullet->GetActive())
			continue;
		if (bullet->GetCollider()->IsOBB(_object))
		{
			_object->SetColor(RED);
			bullet->SetActive(false);
			_timer = RUN_TIME;
		}
	}
	
}

void BowScene::Render()
{
	_sun->Render();
	_player->Render();
	_object->Render();
}
