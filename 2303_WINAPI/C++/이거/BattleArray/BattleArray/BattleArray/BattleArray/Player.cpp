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
		cout << "\"´õºí ¾îÅÃ!\"" << endl;
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
	cout << "\"" << this->_name << "Àº€/´Â " << healNum << "¸¸Å­ È¸º¹Çß´Ù! \"" << endl << endl;
	SOUND->PlayPlayerHeal();
	Sleep(1000);
}

bool Player::Run() const
{
	bool runBool = rand() % 2;

	if (!runBool)
	{
		cout << "\"" << this->_name << " Àº€/´Â µµ¸ÁÃÆ´Ù!\"" << endl << endl;
		SOUND->PlayPlayerRun();
	}
		
	else
		cout << "\"" << this->_name << "Àº€/´Â µµ¸ÁÄ¡Áö ¸øÇß´Ù!.\"" << endl << endl;

	Sleep(1000);

	return runBool;
}

int Player::GetAtk() const
{
	return _atk;
}
