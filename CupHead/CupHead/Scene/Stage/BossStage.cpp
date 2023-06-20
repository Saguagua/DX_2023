#include "framework.h"
#include "BossStage.h"
#include "../../Object/Obj/MainCharacter.h"
#include "../../Object/Obj/Track.h"
#include "../../Object/Obj/Bullet.h"
#include "../../Object/Obj/BackGround.h"
#include "../../Object/Obj/Crown.h"

BossStage::BossStage()
{
	_main = make_shared<MainCharacter>();
	_track = make_shared<Track>(Vector2(WIN_WIDTH, WIN_HEIGHT / 3));
	_background = make_shared<BackGround>();
	_crown = make_shared<Crown>();
	
	_main->GetCollider()->GetTransform()->SetPos(Vector2(WIN_WIDTH/2, WIN_HEIGHT - 300));
	_track->GetCollider()->GetTransform()->SetPos(Vector2(WIN_WIDTH/2, 30));
	_crown->GetCollider()->SetPos(Vector2(WIN_WIDTH - 200, 190));
	_crown->SetEnemy(_main);
	_main->Update();
	_track->Update();
	_background->Update();
	_crown->Update();
}

BossStage::~BossStage()
{
}

void BossStage::Update()
{
	if (_main->GetCollider()->IsCollision(_crown->GetCollider()))
	{
		_main->GetCollider()->SetColor(RED);
		_crown->GetCollider()->SetColor(RED);
		_main->GetDamage(1);
	}
	else
	{
		_main->GetCollider()->SetColor(GREEN);
		_crown->GetCollider()->SetColor(GREEN);
	}

	for (shared_ptr<Bullet> bullet : _main->GetBullets())
	{
		if (!bullet->IsActive())
			continue;

		if (bullet->GetCollider()->IsCollision(_crown->GetCollider()))
		{
			_crown->GetCollider()->SetColor(RED);
			_crown->SetRedTimer(1);
			_crown->GetDamage(1);
			bullet->SetActive(false);
		}
	}
	
	for (shared_ptr<Bullet> bullet : _crown->GetBullets())
	{
		if (!bullet->IsActive())
			continue;

		if (bullet->GetCollider()->IsCollision(_main->GetCollider()))
		{
			_main->GetCollider()->SetColor(RED);
			_main->GetDamage(1);
			bullet->SetActive(false);
		}
	}

	_main->Update();
	_track->Update();
	_background->Update();
	_crown->Update();

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
	_crown->Render();
	_main->Render();
}

void BossStage::PostRender()
{
	_main->PostRender();
	ImGui::Spacing();
	ImGui::Separator();
	ImGui::Spacing();
	_crown->PostRender();
}
