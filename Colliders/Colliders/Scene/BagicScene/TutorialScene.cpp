#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	_rect = make_shared<RectCollider>(Vector2(80.0f, 80.0f));
	_rect2 = make_shared<RectCollider>(Vector2(60.0f, 60.0f));
	_circle = make_shared<CircleCollider>(80.0f);

	_rect2->SetPos(Vector2(100.0f, 100.0f));
	_circle->SetPos(CENTER);

	_rect2->SetParent(_rect);
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	if (_rect2->IsCollision(_circle))
	{
		_rect2->SetColor(RED);
		_circle->SetColor(RED);
	}
	else
	{
		_rect2->SetColor(GREEN);
		_circle->SetColor(GREEN);
	}

	_rect->SetPos(MOUSE_POS);
	_rect->Update();
	_rect2->Update();
	_circle->Update();
}

void TutorialScene::Render()
{
	_rect->Render();
	_rect2->Render();
	_circle->Render();
}
