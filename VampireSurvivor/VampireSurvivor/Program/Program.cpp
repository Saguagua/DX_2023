#include "framework.h"
#include "Program.h"
#include "../Scene/BagiScene/StageScene.h"

Program::Program()
{
	_scene = make_shared<StageScene>();
	_view = make_shared<MatrixBuffer>();
	_proj = make_shared<MatrixBuffer>();

	_view->UpdateData();

	XMMATRIX tmp = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, 0.0f, 1.0f);
	_proj->UpdateMatrix(tmp);

	_proj->UpdateData();
}

Program::~Program()
{
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();
	_scene->Render();
	Device::GetInstance()->Present();
}
