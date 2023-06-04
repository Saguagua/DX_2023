#include "framework.h"
#include "BowScene.h"

BowScene::BowScene()
{
	_player = make_shared<Character>(L"Player");
	_bow = make_shared<Bow>(L"Bow");
	_sun = make_shared<Planet>(L"sun");
	_sun->SetScale(Vector2(0.1f, 0.1f));

	_bow->SetParent(_player->GetTransform());
}

BowScene::~BowScene()
{
}

void BowScene::Update()
{
	Vector2 p = _player->GetTransform()->GetPos();
	Vector2 s = mousePos;
	
	float angle = atan2((s.y - p.y), (s.x - p.x));
	_player->GetTransform()->SetAngle(angle);
	_sun->SetPosition(mousePos);
	_player->Update();
	_bow->Update();
	_sun->Update();
}

void BowScene::Render()
{
	_sun->Render();
	_bow->Render();
	_player->Render();
	_bullet->Render();
}
