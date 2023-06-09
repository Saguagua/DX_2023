#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_mouseCircle = make_shared<CircleCollider>(50, Vector2(mousePos.x, mousePos.y));
	_circle = make_shared<CircleCollider>(80, Vector2(400, 400));
	//_mouseRect = make_shared<RectangleCollider>(Vector2(mousePos.x, mousePos.y), Vector2(300, 50));
	_rect = make_shared<RectangleCollider>(Vector2(600, 400), Vector2(70, 50));
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	Vector2 lerpPos = LERP(_mouseCircle->GetCenter(), mousePos, 0.1f);

	_mouseCircle->SetCenter(mousePos);
	//_mouseRect->SetCenter(mousePos);

	//if (_mouseCircle->IsCollision(_circle))
	//{
	//	_mouseCircle->SetRed();
	//	_circle->SetRed();
	//}
	//else
	//{
	//	_mouseCircle->SetGreen();
	//	_circle->SetGreen();
	//}

	//if (_mouseRect->IsCollision(_rect))
	//{
	//	_rect->SetRed();
	//	_mouseRect->SetRed();
	//}
	//else
	//{
	//	_rect->SetGreen();
	//	_mouseRect->SetGreen();
	//}

	if (_mouseCircle->IsCollision(_rect))
	{
		_rect->SetRed();
		_mouseCircle->SetRed();
	}
	else
	{
		_rect->SetGreen();
		_mouseCircle->SetGreen();
	}
	//if (_mouseRect->IsCollision(_circle))
	//{
	//	_circle->SetRed();
	//	_mouseRect->SetRed();
	//}
	//else
	//{
	//	_circle->SetGreen();
	//	_mouseRect->SetGreen();
	//}
}

void PaintScene::Render(HDC hdc)
{
	_mouseCircle->Render(hdc);
	_circle->Render(hdc);

	//_mouseRect->Render(hdc);
	_rect->Render(hdc);
}
