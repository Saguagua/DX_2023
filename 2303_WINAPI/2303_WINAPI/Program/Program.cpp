#include "framework.h"

#include "Scene/PaintScene.h"
#include "Scene/LineScene.h"
#include "Scene/CannonScene.h"

#include "Program.h"


HDC Program::backBuffer = nullptr;
Program::Program()
{
	HDC hdc = GetDC(hWnd);

	backBuffer = CreateCompatibleDC(hdc);
	hBit = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
	SelectObject(backBuffer, hBit);
	// ¾À ¹Ù²Ù±â
	//_scene = make_shared<LineScene>();
	// 
	//_scene = make_shared<PaintScene>();
	//
	_scene = make_shared<CannonScene>();
}

Program::~Program()
{
	DeleteObject(backBuffer);
	DeleteObject(hBit);
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render(HDC hdc)
{
	PatBlt(backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, BLACKNESS);

	_scene->Render(backBuffer);
	BitBlt(
		hdc,
		0,0,WIN_WIDTH,WIN_HEIGHT,
		backBuffer,0,0,
		SRCCOPY
	);

}
