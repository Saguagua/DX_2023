#include "framework.h"

Monster::Monster()
	:Creature() {}

void Monster::Set(string _name, int _hp, int _atk, int _crit)
{
	this->_name = _name;
	this->_hp = _hp;
	this->_atk = _atk;
	this->_crit = _crit;
}

void Monster::Attack(Player* const target)
{
	if (target->GetState() & (State::DEATH))
		return;
	else if (this->_state & State::DEATH)
		return;
	else if (this->_state & State::STUN)
	{
		cout << this->_name << "은/는 스턴 상태입니다." << endl << endl;
		this->_state = State::NORMAL;
		return;
	}

	cout << this->_name << "의 공격!" << endl;

	int damage = this->_atk + this->Crit(target->GetState());
	target->GetDamage(damage);

	return;
}