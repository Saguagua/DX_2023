#include "framework.h"
#include "SpriteScene.h"
#include "../../Object/Obj/Link.h"

SpriteScene::SpriteScene()
{
	_link = make_shared<Link>();
}


void SpriteScene::Update()
{
	_link->Update();
}

void SpriteScene::Render()
{
	_link->Render();
}
