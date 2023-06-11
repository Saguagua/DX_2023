#include "framework.h"
#include "BowScene.h"

BowScene::BowScene()
{
	_player = make_shared<Character>(L"Player");
	_sun = make_shared<Planet>(L"sun");
	_bullet = make_shared<Bullet>();

	_sun->SetScale(Vector2(0.1f, 0.1f));
}

BowScene::~BowScene()
{
}

void BowScene::Update()
{
	_sun->SetPosition(MOUSE_POS);
	_player->Update();
	_sun->Update();
}

void BowScene::Render()
{
	_sun->Render();
	_player->Render();
	_bullet->Render();
}
