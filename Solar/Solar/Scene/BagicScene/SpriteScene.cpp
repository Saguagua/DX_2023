#include "framework.h"
#include "SpriteScene.h"
#include "../../Object/Obj/Link.h"

SpriteScene::SpriteScene()
{
	_link = make_shared<Link>();
}


void SpriteScene::Update()
{
	_link->Update();
}

void SpriteScene::Render()
{
	_link->Render();
}

void SpriteScene::PostRender()
{
	//ImGui::SliderFloat2("CurFrame", (float*)&_curFrame.x, 0, 10, "%.0f");
	ImGui::Text(_link->GetEvent().c_str());
	ImGui::Text("EventNumber : %d", _link->GetEventNumber());

}
