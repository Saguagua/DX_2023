#include "framework.h"
#include "PaintScene.h"



PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	Vector2 lerp = LERP(_rectangleCollider->GetCenter(), mousePos, 0.1f);
	_circleCollider->SetCenter(mousePos);
	_rectangleCollider->SetCenter(lerp);
}

void PaintScene::Render(HDC hdc)
{
	_circleCollider->Render(hdc);
	_rectangleCollider->Render(hdc);
}
