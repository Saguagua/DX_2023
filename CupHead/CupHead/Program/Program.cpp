#include "framework.h"
#include "Program.h"
#include "../Scene/Stage/BossStage.h"

Program::Program()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	_curScene = make_shared<BossStage>();

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
	EFFECT->Update();
	SOUND->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ALPHA->SetState();
	_curScene->Render();
	EFFECT->Render();

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
