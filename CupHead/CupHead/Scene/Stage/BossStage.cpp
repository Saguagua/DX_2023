#include "framework.h"
#include "BossStage.h"
#include "../../Object/Obj/MainCharacter.h"
#include "../../Object/Obj/Track.h"
#include "../../Object/Obj/Bullet.h"
#include "../../Object/Obj/BackGround.h"
#include "../../Object/Obj/Crown.h"
#include "../../Object/BagicObj/Effect.h"

BossStage::BossStage()
{
	_main = make_shared<MainCharacter>();
	_track = make_shared<Track>(Vector2(WIN_WIDTH, WIN_HEIGHT / 3));
	_background = make_shared<BackGround>();
	_crown = make_shared<Crown>();
	EFFECT->AddEffect("Hyper_Shot", Vector2(100, 100), -PI / 2);
	
	_main->GetCollider()->GetTransform()->SetPos(Vector2(WIN_WIDTH/2, WIN_HEIGHT - 300));
	_track->GetCollider()->GetTransform()->SetPos(Vector2(WIN_WIDTH/2, 30));
	_crown->GetCollider()->SetPos(Vector2(WIN_WIDTH - 200, 190));
	_crown->SetEnemy(_main);
	_main->Update();
	_track->Update();
	_background->Update();
	_crown->Update();
	SOUND->Add("bgm1", "Resource/Sound/BGM.mp3", true);
	SOUND->Add("attack", "Resource/Sound/attack.wav");

	SOUND->Play("bgm1");
	//_effect.lock()->SetAngle(PI / 2);
}

BossStage::~BossStage()
{
}

void BossStage::Update()
{
	
	if (!_main->IsDead())
	{
		

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
				EFFECT->Play("Hyper_Shot", _crown->GetCollider()->GetWorldPos());
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
				SOUND->Play("attack");
			}
		}		
	}
	if (_main->GetCollider()->IsCollision(_crown->GetCollider()) && !_main->IsDead())
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

	_main->Update();

	if (!_track->GetCollider()->Block(_main->GetCollider()))
	{
		_main->SetOnAir();
	}
	else
	{
		_main->SetOnGround();
	}
	
	_track->Update();
	_background->Update();
	_crown->Update();
	EFFECT->Update();
}

void BossStage::Render()
{
	_background->Render();
	_track->Render();
	_crown->Render();
	_main->Render();
	EFFECT->Render();
}

void BossStage::PostRender()
{
	_main->PostRender();
	ImGui::Spacing();
	ImGui::Separator();
	ImGui::Spacing();
	_crown->PostRender();
	ImGui::Spacing();
	ImGui::Separator();
	ImGui::Spacing();
	_track->PostRender();
}
