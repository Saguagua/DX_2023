#include "framework.h"

Monster::Monster(string name, int hp, int atk, int crit)
	:Creature(name, hp, atk, crit) {}

void Monster::Set(string name, int hp, int atk, int crit)
{
	this->_name = name;
	this->_hp = hp;
	this->_atk = atk;
	this->_crit = crit;
}

void Monster::Attack(Creature* const target)
{
	if (target->GetState() & (State::DEATH))
		return;
	else if (this->_state & State::DEATH)
		return;
	else if (this->_state & State::STUN)
	{
		cout << "\"" << this->_name << "Àº€/´Â ½ºÅÏ »óÅÂ´Ù.\"" << endl;
		SOUND->PlayStun();
		this->_state = State::NORMAL;
		cout << endl;
		return;
	}
	cout << "\"" << _name << "ÀÇ °ø°Ý\"" << endl;
	SOUND->PlayMonsterAttack();

	int damage = this->_atk + this->Crit(target->GetState());
	target->GetDamage(damage);

	return;
}

bool Monster::GetDamage(int atk)
{

	cout << "\"" << this->_name << "Àº€/´Â " << atk << "ÀÇ µ¥¹ÌÁö¸¦ ¹Þ¾Ò´Ù\"";
	this->_hp -= atk;

	if (this->_hp <= 0)
	{
		cout << endl << "\"" << this->_name << " Àº/´Â ¾²·¯Á³´Ù!\"" << endl;
		this->GetState() = State::DEATH;
		SOUND->PlayMonsterDeath();
		Sleep(1000);
		return true;
	}

	cout << endl << endl;
	Sleep(1000);
	return false;

}
