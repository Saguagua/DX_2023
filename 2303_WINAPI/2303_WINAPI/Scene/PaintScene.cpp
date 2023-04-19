#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	mousePos;
	_circleCollider;
}

void PaintScene::Render(HDC hdc)
{
	_circleCollider->Render(hdc);
}
