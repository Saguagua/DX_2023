#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	_rect = make_shared<RectCollider>(Vector2(80.0f, 80.0f));
	_rect2 = make_shared<RectCollider>(Vector2(80.0f, 80.0f));
	_circle = make_shared<CircleCollider>(80.0f);
	_circle2 = make_shared<CircleCollider>(80.0f);

	_rect->SetPos(CENTER - Vector2(200, 0));
	_rect2->SetPos(CENTER);
	_circle->SetPos(CENTER - Vector2(200, 0));
	_circle2->SetPos(CENTER);
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_rect->Update();
	_rect2->Update();
	_circle->Update();
	_circle2->Update();

	if (_rect->IsOBB(_rect2))
	{
		_rect2->SetColor(RED);
		_rect->SetColor(RED);
	}
	else
	{
		_rect2->SetColor(GREEN);
		_rect->SetColor(GREEN);
	}
	_circle->Block(_circle2);
	_rect->Block(_rect2);
	_circle2->Block(_rect);
	_rect->SetPos(_pos);
	_rect->SetAngle(_angle);
	_rect->SetScale(_scale);
	
	//_circle->AddPos(Vector2(1.0f ,0.0f) * DELTA * 20.0f);
}

void TutorialScene::Render()
{
	_rect->Render();
	_rect2->Render();
	_circle->Render();
	_circle2->Render();
}

void TutorialScene::PostRender()
{
	ImGui::SliderFloat2("Pos", (float*)&_pos, 0, WIN_WIDTH, "%.0f");
	ImGui::SliderFloat2("Scale", (float*)&_scale, 0, 3, "%.1f");
	ImGui::SliderFloat("Angle", &_angle, 0, 2 * PI, "%.1f");
}