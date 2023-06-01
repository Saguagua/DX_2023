#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	_quad = make_shared<Quad>(WINTER);
	//_line = make_shared<Line>();
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_quad->Update();

	//_line->Update();
}

void TutorialScene::Render()
{
	_quad->TextureRender();
	//_line->Render();
}

