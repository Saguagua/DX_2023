#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	//_rect = make_shared<RectCollider>(Vector2(10.0f, 10.0f));
	//_rect->SetPos(CENTER);
	_circle = make_shared<CircleCollider>(202.0f);
	_circle->SetPos(CENTER);
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	//_rect->Update();
	_circle->Update();
}

void TutorialScene::Render()
{
	//_rect->Render();
	_circle->Render();
}
