#include "framework.h"
#include "Program.h"

#include "../Scene/TutorialScene.h"
#include "../Scene/SolarSystemScene.h"

Program::Program()
{
	_curScene = make_shared<SolarSystemScene>();
	_view = make_shared<MatrixBuffer>();
	_proj = make_shared<MatrixBuffer>();

	_view->Update_Resource();

	XMMATRIX tmp = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, 0.0f, 1.0f);
	//직교 투영 행렬을 생성
	_proj->SetData(tmp);
	_proj->Update_Resource();

	_view->SetVS_Buffer(1);
	_proj->SetVS_Buffer(2);
}

Program::~Program()
{
}

void Program::Update()
{
	_curScene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	_curScene->Render();
	
	Device::GetInstance()->Present();
}
