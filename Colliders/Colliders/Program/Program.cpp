#include "framework.h"
#include "Program.h"
#include "../Scene/BagicScene/TutorialScene.h"


Program::Program()
{
	_scene = make_shared<TutorialScene>();
	_view = make_shared<MatrixBuffer>();
	_proj = make_shared<MatrixBuffer>();
	
	_view->Update_Resource();

	XMMATRIX tmp = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, 0.0f, 1.0f);

	_proj->SetData(tmp);
	_proj->Update_Resource();
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

	_view->SetVS_Buffer(1);
	_proj->SetVS_Buffer(2);

	_scene->Render();

	Device::GetInstance()->Present();
}
