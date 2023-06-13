#include "framework.h"
#include "BowScene.h"

BowScene::BowScene()
{
	_stage = make_shared<Quad>(L"Resource/Texture/Stage1.png", Vector2(WIN_WIDTH, WIN_HEIGHT));
	_player = make_shared<Character>(L"Player");

	_monsters.resize(30);
	for (int i = 0; i < _monsters.size(); i++)
	{
		shared_ptr<Monster> mon = make_shared<Monster>();
		float x = rand() % WIN_WIDTH;
		float y = rand() % WIN_HEIGHT;
		mon->GetCollider()->SetPos(Vector2(x, y));
		_monsters[i] = mon;
	}
}

BowScene::~BowScene()
{
}

void BowScene::Update()
{
	_spawnTimer -= DELTA_TIME;
	if (_spawnTimer < 0.0)
	{
		SpawnMonsters();
		_spawnTimer = 10.0;
	}

	_stage->Update();
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
				if (monster->GetTimer() <= 0.0)
				{
					monster->SetTimer(1.5);
					monster->GetDamage(1);
					monster->GetCollider()->AddPos(dir * -50.0f);
				}
			}
		}

		monster->GetCollider()->AddPos(dir * DELTA_TIME * 50.0f);
		monster->GetCollider()->Block(_player->GetCollider());
	}
	
	
}

void BowScene::Render()
{
	_stage->Render();
	_player->Render();
	for (auto monster : _monsters)
	{
		monster->Render();
	}
}

void BowScene::SpawnMonsters()
{
	int count = 0;
	int side = rand() % 2;
	float x = rand() % WIN_WIDTH;
	float y = rand() % WIN_HEIGHT;

	for (int i = 0; i < _monsters.size(); i++)
	{
		if (count == 10)
			break;
		if (_monsters[i]->GetHP() <= 0)
		{
			side = rand() % 4;
			switch (side)
			{
			case 0:
			{
				x = -10.0f;
				y = rand() % WIN_WIDTH;
				break;
			}
			case 1:
			{
				x = WIN_WIDTH + 10.0f;
				y = rand() % WIN_WIDTH;
				break;
			}
			case 2:
			{
				y = -10.0f;
				x = rand() % WIN_WIDTH;
				break;
			}
			case 3:
			{
				y = WIN_HEIGHT + 10.0f;
				x = rand() % WIN_WIDTH;
				break;
			}
				
			}
			
			_monsters[i]->GetCollider()->SetPos(Vector2(x, y));
			
			_monsters[i]->SetHp(3);
			count++;
		}
	}
	
}
