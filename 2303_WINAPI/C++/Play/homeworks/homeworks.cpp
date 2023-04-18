#include <iostream>
#include <Windows.h>

using namespace std;

enum MainCommand 
{
	SHOWINFO = 1,
	FULLHP,
	FIGHT,
	MODE
};

enum FightCommand
{
	ATTACK = 1,
	HEAL,
	RUN
};

struct Player 
{
	string name;
	int hp;
	int atk;
	bool death;
};

void SetInfo(Player* const player, string name, int hp, int atk);
void SetInfo(Player& player, string name, int hp, int atk);
void ShowInfo(const Player* const player);
void ShowInfo(const Player& player);
void SetHp(Player* const player, int num);
void SetHp(Player& player, int num);
void Fight(Player* const player, Player* const enemy);
void Fight(Player& player, Player& enemy);
void Attack(int damage, Player* const target);
void Attack(int damage, Player& target);
void Heal(Player* const target);
void Heal(Player& target);

int main()
{
	string name;
	int playerInput;
	bool mode = true;
	Player player;

	srand(unsigned int(time(nullptr)));

	cout << "이름 입력 : ";
	cin >> name;

	SetInfo(&player, name, 100, 20);
	while (true) {
		if (mode) cout << "----- 포인터 모드 -----" << endl;
		else cout << "----- 참조 모드 -----" << endl;
		cout << "1. 정보 보기" << endl;
		cout << "2. 체력 회복" << endl;
		cout << "3. 싸우기" << endl;
		cout << "4. 모드 전환" << endl;
		cin >> playerInput;

		switch (playerInput)
		{
		case MainCommand::SHOWINFO: {
			if (mode) ShowInfo(&player);
			else ShowInfo(player);
			break;
		}
		case MainCommand::FULLHP: {
			cout << "체력을 모두 회복합니다." << endl;
			if (mode) SetHp(&player, 100);
			else SetHp(player, 100);
			break;
		}
		case MainCommand::FIGHT: {
			Player enemy;
			if (mode) {
				SetInfo(&enemy, "적", 100, 20);
				Fight(&player, &enemy);
			}
			else {
				SetInfo(enemy, "적", 100, 20);
				Fight(player, enemy);
			}
			break;
		}
		case MainCommand::MODE: {
			mode = !mode;
		}
		}
	}
}


void Fight(Player* const player, Player* const enemy)
{
	int playerInput;
	int randNum;
	bool playB = true;

	while (playB)
	{
		system("cls");
		ShowInfo(player);
		ShowInfo(enemy);

		cout << "플레이어의 차례" << endl;
		cout << "1. 공격   2. 회복   3. 도망치기" << endl;
		cin >> playerInput;

		switch (playerInput)
		{
		case FightCommand::ATTACK: {
			Attack(player->atk, enemy);
			break;
		}
		case FightCommand::HEAL: {
			Heal(player);
			break;
		}
		case FightCommand::RUN: {
			randNum = rand() % 2;
			if (randNum)
			{
				cout << "도망치기 성공!" << endl;
				playB = false;
			}
			else cout << "도망치기 실패" << endl;
		}
		}

		if (playB == false) break;

		if (enemy->death) {
			cout << "이겼습니다!" << endl;
			playB = false;
		}

		cout << enemy->name << " 의 차례" << endl;
		Attack(enemy->atk, player);

		if (player->death) {
			cout << "졌습니다.." << endl;
			playB = false;
		}
		Sleep(1000);
	}
}

void Fight(Player& player, Player& enemy)
{
	int playerInput;
	int randNum;
	bool playB = true;

	while (playB)
	{
		system("cls");
		ShowInfo(player);
		ShowInfo(enemy);

		cout << "플레이어의 차례" << endl;
		cout << "1. 공격   2. 회복   3. 도망치기" << endl;
		cin >> playerInput;

		switch (playerInput)
		{
		case FightCommand::ATTACK: {
			Attack(player.atk, enemy);
			break;
		}
		case FightCommand::HEAL: {
			Heal(player);
			break;
		}
		case FightCommand::RUN: {
			randNum = rand() % 2;
			if (randNum)
			{
				cout << "도망치기 성공!" << endl;
				playB = false;
			}
			else cout << "도망치기 실패" << endl;
		}
		}

		if (playB == false) break;

		if (enemy.death) {
			cout << "이겼습니다!" << endl;
			playB = false;
		}

		cout << enemy.name << " 의 차례" << endl;
		Attack(enemy.atk, player);

		if (player.death) {
			cout << "졌습니다.." << endl;
			playB = false;
		}
		Sleep(1000);
	}
}

void SetInfo(Player* const player, string name, int hp, int atk)  //포인터
{
	player->name = name;
	player->hp = hp;
	player->atk = atk;
	player->death = false;
}

void SetInfo(Player& player, string name, int hp, int atk)  //참조
{
	player.name = name;
	player.hp = hp;
	player.atk = atk;
	player.death = false;
}

void ShowInfo(const Player* const player)  //포인터
{
	cout << "이름 : " << player->name << endl;
	cout << "체력 : " << player->hp << "/100" << endl;
	cout << "공격력 : " << player->atk << endl << endl;
}

void ShowInfo(const Player& player)  //참조
{
	cout << "이름 : " << player.name << endl;
	cout << "체력 : " << player.hp << "/100" << endl;
	cout << "공격력 : " << player.atk << endl << endl;
}

void SetHp(Player* const player, int num)  //포인터
{
	player->hp += num;
	if (player->hp > 100) player->hp = 100;
}

void SetHp(Player& player, int num)  //참조
{
	player.hp = num;
	if (player.hp > 100) player.hp = 100;
}

void Attack(int damage, Player* const target)  //포인터
{
	target->hp -= damage;
	cout << damage << " 데미지!" << endl << endl;
	if (target->hp <= 0) target->death = true;
}

void Attack(int damage, Player& target)  //참조
{
	target.hp -= damage;
	cout << damage << " 데미지!" << endl << endl;
	if (target.hp <= 0) target.death = true;
}

void Heal(Player* const target)  //포인터
{
	int num = rand() % 20 + 10;

	cout << num << "만큼 회복!" << endl << endl;
	SetHp(target, num);
}

void Heal(Player& target)  //참조
{
	int num = rand() % 20 + 10;

	cout << num << "만큼 회복!" << endl << endl;
	SetHp(target, num);
}