#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	_quad = make_shared<Quad>(WINTER);
	//_line = make_shared<Line>();

	_world = make_shared<MatrixBuffer>();
	_view = make_shared<MatrixBuffer>();
	_proj = make_shared<MatrixBuffer>();

	_world->Update_Resource();
	_view->Update_Resource();

	XMMATRIX tmp = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, 0.0f, 1.0f);
	//직교 투영 행렬을 생성
	_proj->SetData(tmp);
	_proj->Update_Resource();
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	InputCheck();
	XMMATRIX scale = XMMatrixScaling(_xScale, _yScale, 0);
	XMMATRIX rotate = XMMatrixRotationZ(XMConvertToRadians(_angle));
	//라디안 각도를 사용한다.
	XMMATRIX translate = XMMatrixTranslation(_x, _y, 0);
	XMMATRIX srt = XMMatrixMultiply(scale, rotate);
	srt = XMMatrixMultiply(srt, translate);
	_world->SetData(srt);
	
	_world->Update_Resource();

	_quad->Update();
	//_line->Update();
}

void TutorialScene::Render()
{
	_world->SetVS_Buffer(0);
	_view->SetVS_Buffer(1);
	_proj->SetVS_Buffer(2);

	_quad->TextureRender();
	//_line->Render();
}

void TutorialScene::InputCheck()
{
	if (GetAsyncKeyState('A'))
	{
		_x -= 0.1f;
	}
	if (GetAsyncKeyState('D'))
	{
		_x += 0.1f;
	}
	if (GetAsyncKeyState('W'))
	{
		_y += 0.1f;
	}
	if (GetAsyncKeyState('S'))
	{
		_y -= 0.1f;
	}
	if (GetAsyncKeyState('Q'))
	{
		_angle += 0.01f;
	}
	if (GetAsyncKeyState('E'))
	{
		_angle -= 0.01f;
	}
	if (GetAsyncKeyState('R'))
	{
		_xScale += 0.0001;
	}
	if (GetAsyncKeyState('T'))
	{
		if (_xScale < 0)
			return;
		_xScale -= 0.0001;
	}
	if (GetAsyncKeyState('Y'))
	{
		_yScale += 0.0001;
	}
	if (GetAsyncKeyState('U'))
	{
		if (_yScale < 0)
			return;
		_yScale -= 0.0001;
	}
}
