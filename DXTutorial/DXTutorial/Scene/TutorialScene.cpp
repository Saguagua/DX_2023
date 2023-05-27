#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	_quad = make_shared<Quad>();
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_quad->Update();
}

void TutorialScene::Render()
{
	_quad->Render();
}
