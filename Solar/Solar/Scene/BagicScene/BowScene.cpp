#include "framework.h"
#include "BowScene.h"

BowScene::BowScene()
{
	_player = make_shared<Character>(L"Player");
	shared_ptr<Monster> mon = make_shared<Monster>();
	mon->GetCollider()->SetPos(CENTER - Vector2(200.0f, 0.0f));
	_monsters.push_back(mon);
}

BowScene::~BowScene()
{
}

void BowScene::Update()
{
	_player->Update();

	for (auto monster : _monsters)
	{
		if (monster->GetHP() <= 0)
			continue;
		monster->Update();

		shared_ptr<CircleCollider> col = monster->GetCollider();
		Vector2 dir = _player->GetTransform()->GetWorldPos() - monster->GetCollider()->GetWorldPos();
		dir.Normalize();

		for (auto bullet : _player->GetBullets())
		{
			if (!bullet->GetActive())
				continue;
			if (bullet->GetCollider()->IsCollision(col))
			{
				monster->GetDamage(1);
				bullet->SetActive(false);
				
			}
		}

		for (auto vible : _player->GetVibles())
		{
			if (vible->GetCollider()->IsCollision(col))
			{
				if (_timer + 2 < RUN_TIME || _timer == 0)
				{
					monster->GetDamage(1);
					monster->GetCollider()->AddPos(dir * -50.0f);
					_timer = RUN_TIME;
				}				
			}
		}

		monster->GetCollider()->AddPos(dir * DELTA_TIME * 50.0f);
		monster->GetCollider()->Block(_player->GetCollider());
	}
	
	
}

void BowScene::Render()
{
	_player->Render();
	for (auto monster : _monsters)
	{
		monster->Render();
	}
}
