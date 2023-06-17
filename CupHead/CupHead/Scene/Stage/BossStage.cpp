#include "framework.h"
#include "BossStage.h"

BossStage::BossStage()
{
	_main = make_shared<MainCharacter>();
	_main->GetCollider()->GetTransform()->SetPos(CENTER);
}

BossStage::~BossStage()
{
}

void BossStage::Update()
{
	_main->Update();
}

void BossStage::Render()
{
	_main->Render();
}

void BossStage::PostRender()
{
}
