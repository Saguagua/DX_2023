#include "framework.h"
#include "BackGround.h"

BackGround::BackGround()
{
	_quad = make_shared<Quad>(L"Resource/Background/clown_bg_main.png");
	_transform = make_shared<Transform>();
	_transform->SetPos(CENTER);
}

void BackGround::Update()
{
	_transform->Update();
}

void BackGround::Render()
{
	_transform->Set_World(0);
	_quad->Render();
}
