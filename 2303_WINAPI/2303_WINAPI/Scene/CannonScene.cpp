#include "framework.h"
#include "CannonScene.h"

CannonScene::CannonScene()
{
	tank = make_shared<Tank>();
	circle = make_shared<CircleCollider>(100, Vector2(500, 500));
}

void CannonScene::Update()
{
	tank->Update();

	vector<shared_ptr<Bullet>> v = tank->GetBullets();

	for (auto bullet : v)
	{
		if (!bullet->IsActive()) return;

		bullet->AttackObject(circle);
	}
}

void CannonScene::Render(HDC hdc)
{
	tank->Render(hdc);
	circle->Render(hdc);
}
