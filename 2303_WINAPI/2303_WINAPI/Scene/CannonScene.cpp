#include "framework.h"
#include "CannonScene.h"

CannonScene::CannonScene()
{
	tank = make_shared<Tank>();
}

void CannonScene::Update()
{
	tank->Update();
}

void CannonScene::Render(HDC hdc)
{
	tank->Render(hdc);
}
