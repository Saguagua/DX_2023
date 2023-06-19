#include "framework.h"
#include "BossStage.h"
#include "../../Object/Obj/MainCharacter.h"
#include "../../Object/Obj/Track.h"
#include "../../Object/Obj/Bullet.h"
#include "../../Object/Obj/BackGround.h"

BossStage::BossStage()
{
	_main = make_shared<MainCharacter>();
	_track = make_shared<Track>(Vector2(WIN_WIDTH, WIN_HEIGHT / 3));
	_background = make_shared<BackGround>();
	_main->GetCollider()->GetTransform()->SetPos(Vector2(WIN_WIDTH/2, WIN_HEIGHT - 300));
	_track->GetCollider()->GetTransform()->SetPos(Vector2(WIN_WIDTH/2, 30));
	
}

BossStage::~BossStage()
{
}

void BossStage::Update()
{
	_main->Update();
	_track->Update();
	_background->Update();

	
	if (!_track->GetCollider()->Block(_main->GetCollider()))
	{
		_main->SetOnAir();
	}
	else
	{
		_main->SetOnGround();
	}
}

void BossStage::Render()
{
	_background->Render();
	_track->Render();
	_main->Render();
}

void BossStage::PostRender()
{
	_main->PostRender();
}
