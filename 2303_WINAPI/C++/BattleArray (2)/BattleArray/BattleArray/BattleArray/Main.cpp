#include "framework.h"

#define SIZE 10

void PrintAll(Player* const player, Monster* const arr, int size);
void Battle(Player* const player, Monster* const arr, int size);

int main()
{
	srand(unsigned int(time(nullptr)));
	string name;
	Monster arr[SIZE];

	cout << "이름 입력 : ";
	cin >> name;
	cout << endl;

	Player player = Player(name);

	for (int i = 0; i < SIZE; i++)
	{
		string name = "몬스터" + to_string(i+1);
		int hp = rand() % 45 + 1;
		int atk = rand() % 5 + 1;
		int crit = 0;

		arr[i].Set(name, hp, atk, crit);
	}

	PrintAll(&player, arr, SIZE);

	Battle(&player, arr, SIZE);

	PrintAll(&player, arr, SIZE);
}

void PrintAll(Player* const player, Monster* const arr, int size)
{
	player->PrintInfo();

	for (int i = 0; i < SIZE; i++)
		arr[i].PrintInfo();

	cout << endl;
	
	Sleep(1000);
}

void Battle(Player* const player, Monster* const arr, int size)
{
	int input;
	int count = 0;
	bool play = true;

	while (play)
	{
		cout << "----- 플레이어의 턴 -----" << endl;
		cout << "1. 공격  2. 회복  3. 도망치기 :";
		cin >> input;
		cout << endl;
		count = 0;
		
		switch (input) {
		case ATTACK:
		{
			for (int i = 0; i < size; i++) {
				player->Attack(&arr[i]);
				if (arr[i].IsDead())
					count++;
			}
			break;
		}
		case HEAL:
		{
			player->Heal();
			break;
		}
		case RUN:
		{
			play = player->Run();
			break;
		}
		default:
		{
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
		}

		if (count == size || play == false) break;

		PrintAll(player, arr, size);
		cout << "계속하려면 아무 키나 입력 : ";
		cin >> input;

		cout << "----- 적의 턴 -----" << endl;

		for (int i = 0; i < size; i++)
		{
			arr[i].Attack(player);
			if (player->IsDead())
				break;
		}
		
		PrintAll(player, arr, size);
	}
}
