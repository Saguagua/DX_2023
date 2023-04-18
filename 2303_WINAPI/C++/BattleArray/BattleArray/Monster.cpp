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
		cout << "\"" << this->_name << "은/는 스턴 상태입니다.\"" << endl;
		SOUND->PlayStun();
		this->_state = State::NORMAL;
		cout << endl;
		return;
	}
	cout << "\"" << _name << "의 공격\"" << endl;
	SOUND->PlayMonsterAttack();
	Creature::Attack(target);

	return;
}

bool Monster::GetDamage(int atk)
{
	if (Creature::GetDamage(atk))
		SOUND->PlayMonsterDeath();
	return false;
}
