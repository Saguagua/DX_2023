#include "framework.h"

Creature::Creature()
	:_MaxHp(100), _name(""), _hp(0), _atk(0), _state(0), _crit(0){}

unsigned char& Creature::GetState()
{
	return _state;
}

void Creature::Attack(Creature* const target)
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

void Creature::GetDamage(int atk)
{
	cout << this->_name << "은/는 " << atk << "만큼의 데미지를 받았다!";
	this->_hp -= atk;

	if (this->_hp <= 0)
	{
		cout << endl << this->_name << "은 쓰러졌다!";
		this->GetState() = State::DEATH;
	}

	cout << endl << endl;
	Sleep(1000);
	return;
}

bool Creature::IsDead() const
{
	if (this->_state & (State::DEATH)) 
		return true;

	return false;
}

int Creature::Crit(unsigned char& state) const
{
	int randInt = rand() % 100 + 1;

	if (randInt <= this->_crit)
	{
		cout << "크리티컬 데미지!" << endl;
		state |= State::STUN;
		return (this->_atk / 2);
	}

	return 0;
}

void Creature::PrintInfo() const
{
	if (_state & (State::DEATH)) return;

	cout << _name;
	cout << " hp : " << _hp;
	cout << " atk : " << _atk;
	if (_state & (State::STUN)) cout << " (Stun)";
	cout << endl;
}
