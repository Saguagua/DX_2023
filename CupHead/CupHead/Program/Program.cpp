#include "framework.h"
#include "Program.h"
#include "../Scene/Stage/BossStage.h"

Program::Program()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	_curScene = make_shared<BossStage>();

	_view = make_shared<MatrixBuffer>();
	_proj = make_shared<MatrixBuffer>();

	_view->Update_Resource();

	XMMATRIX temp = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, 0.0f, 1.0f);

	_proj->SetMatrix(temp);
	_proj->Update_Resource();

	Timer::GetInstance()->LockRunTime(60.0);
}

Program::~Program()
{
}

void Program::Update()
{
	Timer::GetInstance()->Update();
	InputManager::GetInstance()->Update();
	_curScene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	_view->SetVS_Buffer(1);
	_proj->SetVS_Buffer(2);

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ALPHA->SetState();
	_curScene->Render();

	ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[0]); 
	ImGui::SetWindowFontScale(1.2f);
	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f)); 
	
	ImGui::Text("Timer");

	ImGui::PopFont();
	ImGui::PopStyleColor();
	ImGui::SetWindowFontScale(1.0f);

	ImGui::Text("FPS : %d", FPS);
	ImGui::Text("DeltaTime : %1f", DELTA_TIME);
	ImGui::Text("RunTime : %1f", RUN_TIME);

	ImGui::Spacing();
	ImGui::Separator();
	ImGui::Spacing();

	_curScene->PostRender();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
