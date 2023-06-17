#include "framework.h"
#include "BossStage.h"

BossStage::BossStage()
{
	_cir = make_shared<CircleCollider>(100.0f);
	_rec = make_shared<RectCollider>(Vector2(100.0f, 100.0f));
	Vector2 center = CENTER;
	_cir->GetTransform()->SetPos(CENTER);
	_rec->GetTransform()->SetPos(CENTER - Vector2(60.0f, 60.0f));
}

BossStage::~BossStage()
{
}

void BossStage::Update()
{
	_cir->GetTransform()->SetPos(MOUSE_POS);
	_rec->GetTransform()->AddPos(UP_VECTOR * DELTA_TIME * 200.0f);
	_cir->Update();
	_rec->Update();
}

void BossStage::Render()
{
	_cir->Render();
	_rec->Render();
}

void BossStage::PostRender()
{
}
