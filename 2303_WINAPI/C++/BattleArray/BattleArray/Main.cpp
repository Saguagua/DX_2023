#include "framework.h"

#define SIZE 11

void PrintAll(Creature** const arr, int size);
void Battle(Creature** const arr, int size);

int main()
{
	srand(unsigned int(time(nullptr)));
	string name;
	Creature* arr[SIZE];
	SoundManager::Create();

	cout << "이름 : ";
	cin >> name;
	cout << endl;
	arr[0] = new Player(name);

	for (int i = 1; i < SIZE; i++)
	{
		string name = "몬스터" + to_string(i);
		int hp = rand() % 45 + 1;
		int atk = rand() % 5 + 1;
		int crit = 0;

		arr[i] = new Monster(name, hp, atk, crit);
	}

	PrintAll(arr, SIZE);

	Battle(arr, SIZE);

	PrintAll(arr, SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		delete arr[i];
	}
	SoundManager::Delete();
}

void PrintAll(Creature** const arr, int size)
{

	for (int i = 0; i < size; i++)
		arr[i]->PrintInfo();

	cout << endl;
	
	Sleep(1000);
}

void Battle(Creature** const arr, int size)
{
	int input;
	int count = 0;
	bool play = true;

	Creature* player = arr[0];

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
			for (int i = 1; i < size; i++) {
				player->Attack(arr[i]);
				if (arr[i]->IsDead())
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

		if (count == size-1 || play == false) break;

		PrintAll(arr, size);
		cout << "아무 키나 입력 : ";
		cin >> input;

		cout << "----- Enemy's turn -----" << endl;

		for (int i = 1; i < size; i++)
		{
			arr[i]->Attack(player);
			if (player->IsDead())
				break;
		}
		
		PrintAll(arr, size);
	}
}
