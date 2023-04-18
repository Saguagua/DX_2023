#include "framework.h"

Creature::Creature()
	:_MaxHp(100), _name(""), _hp(0), _atk(0), _state(0), _crit(0) {}

Creature::Creature(string name, int hp, int atk, int crit)
	: _MaxHp(100), _name(name), _hp(hp), _atk(atk), _state(0), _crit(crit) {}

unsigned char& Creature::GetState()
{
	return _state;
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
	cout << endl;
}
