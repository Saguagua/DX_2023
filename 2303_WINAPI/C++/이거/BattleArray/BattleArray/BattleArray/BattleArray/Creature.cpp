#include "framework.h"

Creature::Creature()
	:_MaxHp(100), _name(""), _hp(0), _atk(0), _state(0), _crit(0) {}

Creature::Creature(string name, int hp, int atk, int crit)
	: _MaxHp(100), _name(name), _hp(hp), _atk(atk), _state(0), _crit(crit) {}

unsigned char& Creature::GetState()
{
	return _state;
}

bool Creature::CheckState()
{
	switch (_state)
	{

	case State::DEATH :
		return false;
		
	case State::STUN :
	{
		cout << _name << "은/는 스턴 상태입니다!" << endl;
		this->_state = State::NORMAL;
		return false;
	}
	case State::RUN :
		cout << _name << "은/는 도망가서 없습니다." << endl;

	}

	return false;
}

void Creature::Attack(Creature* const target)
{
	if(!CheckState()) return;

	cout << "\"" << _name << "의 공격!\"" << endl;
	SOUND->PlayPlayerAttack();
	int damage = this->_atk + this->Crit(target->GetState());
	target->GetDamage(damage);

}

bool Creature::GetDamage(int atk)
{
	cout << "\"" << this->_name << "은/는 " << atk << "만큼의 데미지를 받았다!";
	this->_hp -= atk;

	if (this->_hp <= 0)
	{
		cout << endl << "\"" << this->_name << " 은�/는 쓰러졌다!\"" << endl;
		this->GetState() = State::DEATH;
		SOUND->PlayPlayerDeath();
		Sleep(1000);
		return true;
	}

	return false;
}

int Creature::Crit(unsigned char& state) const
{
	int randInt = rand() % 100 + 1;

	if (randInt <= this->_crit)
	{
		cout << "\"크리티컬!\"" << endl;
		SOUND->PlayCrit();
		state |= State::STUN;

		return (this->_atk / 2);
	}

	return 0;
}

bool Creature::IsDead() const
{
	if (this->_state & (State::DEATH)) 
		return true;

	return false;
}

void Creature::PrintInfo() const
{
	if (_state & (State::DEATH)) return;

	cout << _name;
	cout << " hp : " << _hp;
	cout << " atk : " << _atk;
	if (_state & (State::STUN)) cout << " (Stun)";
	else if (_state & (State::RUN)) cout << " (도망감)";
	cout << endl;
}
