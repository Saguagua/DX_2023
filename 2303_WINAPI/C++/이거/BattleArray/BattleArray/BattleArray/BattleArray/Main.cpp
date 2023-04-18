#include "framework.h"

void PrintAll(const vector<Creature*> const);
void Battle(const vector<Creature*> const);
void BossBattle(const vector<Creature*> const);

int main()
{
	srand(unsigned int(time(nullptr)));
	string name;
	vector<Creature*> vector;
	vector.reserve(11);
	
	SoundManager::Create();

#pragma region 1대 10 배틀
	//cout << "이름 : ";
	//cin >> name;
	//cout << endl;
	//vector.push_back(new Player(name));

	//for (int i = 0; i < 10; i++)
	//{
	//	string name = "몬스터" + to_string(i);
	//	int hp = rand() % 45 + 1;
	//	int atk = rand() % 5 + 1;
	//	int crit = 0;

	//	vector.push_back(new Monster(name, hp, atk, crit));
	//}

	//PrintAll(vector);

	//Battle(vector);

	//PrintAll(vector);
#pragma endregion

#pragma region 보스 배틀
	vector.push_back(new Boss());

	for (int i = 0; i < 10; i++)
	{
		int hp = rand() % 45 + 30;
		int atk = rand() % 20 + 10;
		int crit = rand() % 20 + 1;

		int type = rand() % 3 + 1;

		Creature* player;

		switch (type)
		{
			case Class::KNIGHT :
			{
				player = new Knight("기사" + to_string(i + 1), hp, atk, crit);
				break;
			}
			case Class::MAGE :
			{
				player = new Mage("마법사" + to_string(i + 1), hp, atk, crit);
				break;
			}
			case Class::ARCHER :
			{
				player = new Archer("궁수" + to_string(i+1), hp, atk, crit);
			}
		}

		vector.push_back(player);
	}

	PrintAll(vector);

#pragma endregion

	for (int i = 0; i < vector.size(); i++)
	{
		delete vector[i];
	}

	SoundManager::Delete();

}

void PrintAll(const vector<Creature*> const vector)
{

	for (int i = 0; i < vector.size(); i++)
		vector[i]->PrintInfo();

	cout << endl;
	
	Sleep(1000);
}

#pragma region 1 대 10 배틀
void Battle(vector<Creature*> const vector)
{
	int input;
	int count = 0;
	bool play = true;

	Creature* player = vector[0];

	while (play)
	{
		cout << "----- Player's turn -----" << endl;
		cout << "1. 공격  2. 회복  3. 도망치기 :";
		cin >> input;
		cout << endl;
		count = 0;
		
		switch (input) {
		case ATTACK:
		{
			for (int i = 1; i < vector.size(); i++) {
				player->Attack(vector[i]);
				if (vector[i]->IsDead())
					count++;
			}
			break;
		}
		case HEAL:
		{
			dynamic_cast<Player*>(player)->Heal();
			break;
		}
		case RUN:
		{
			play = dynamic_cast<Player*>(player)->Run();
			break;
		}
		default:
		{
			cout << "잘못된 입력." << endl;
			continue;
		}
		}

		if (count == vector.size()-1 || play == false) break;

		PrintAll(vector);
		cout << "아무 키나 입력 : ";
		cin >> input;

		cout << "----- Enemy's turn -----" << endl;

		for (int i = 1; i < vector.size(); i++)
		{
			vector[i]->Attack(player);
			if (player->IsDead())
				break;
		}
		
		PrintAll(vector);
	}
}
#pragma endregion

void BossBattle(vector<Creature*> const v)
{
	int randNum;
	cout << "보스 배틀" << endl;

	Creature* boss = v[0];

	while (true)
	{
		for (int i = 1; i < 11; i++)
		{
			randNum = rand() / 3;
			
			if (randNum == Command::ATTACK)
				v[i]->Attack(boss);
			else if (randNum == Command::SKILL)
				dynamic_cast<Player*>(v[i])->Skill(v);
			else if (randNum == Command::HEAL)
				dynamic_cast<Player*>(v[i])->Heal();
			else if (randNum == Command::RUN)
				dynamic_cast<Player*>(v[i])->Run();
		}

		if (boss->IsDead())
		{
			cout << "보스를 쓰러뜨렸습니다!" << endl;
			break;
		}

		for (int i = 1; i < 11; i++)
		{
			
		}
	}

	
}

