#include "framework.h"

void PrintAll(const vector<Creature*> const);
void Battle(const vector<Creature*> const);

int main()
{
	srand(unsigned int(time(nullptr)));
	string name;
	vector<Creature*> vector;
	vector.reserve(11);
	
	map<int, int> m;
	m.insert(1, 1);
	m.insert(2, 5);
	m.insert(3, 2);

	for (int i = 1 ;i <= m.size(); i++)
		cout << m[i] << endl;

	SoundManager::Create();

	cout << "이름 : ";
	cin >> name;
	cout << endl;
	vector.push_back(new Player(name));

	for (int i = 0; i < 10; i++)
	{
		string name = "몬스터" + to_string(i);
		int hp = rand() % 45 + 1;
		int atk = rand() % 5 + 1;
		int crit = 0;

		vector.push_back(new Monster(name, hp, atk, crit));
	}

	PrintAll(vector);

	Battle(vector);

	PrintAll(vector);

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
