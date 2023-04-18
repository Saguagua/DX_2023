#include "framework.h"

Player::Player(string name)
	:Creature(name, 100, 10, 20)
{}

Player::Player(string name, int hp, int atk, int crit)
	:Creature(name, hp, atk, crit)
{
}

void Player::Attack(Creature* const target)
{
	Creature::Attack(target);

	if (this->MultipleAttack() && !(target->IsDead()))
	{
		cout << "\"���� ����!\"" << endl;
		Creature::Attack(target);
	}

	return;
}

bool Player::MultipleAttack()
{
	return rand() / 2;
}

void Player::Heal()
{
	if (!CheckState()) return;

	int healNum = rand() % 20 + 10;

	if (healNum + this->_hp > _MaxHp)
		healNum = _MaxHp - this->_hp;

	this->_hp += healNum;
	cout << "\"" << this->_name << "���/�� " << healNum << "��ŭ ȸ���ߴ�! \"" << endl << endl;
	SOUND->PlayPlayerHeal();
	Sleep(1000);
}

bool Player::Run() const
{
	bool runBool = rand() % 2;

	if (!runBool)
	{
		cout << "\"" << this->_name << " ���/�� �����ƴ�!\"" << endl << endl;
		SOUND->PlayPlayerRun();
	}
		
	else
		cout << "\"" << this->_name << "���/�� ����ġ�� ���ߴ�!.\"" << endl << endl;

	Sleep(1000);

	return runBool;
}

int Player::GetAtk() const
{
	return _atk;
}
