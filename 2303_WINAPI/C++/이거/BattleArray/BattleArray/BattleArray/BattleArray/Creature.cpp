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
		cout << _name << "Àº/´Â ½ºÅÏ »óÅÂÀÔ´Ï´Ù!" << endl;
		this->_state = State::NORMAL;
		return false;
	}
	case State::RUN :
		cout << _name << "Àº/´Â µµ¸Á°¡¼­ ¾ø½À´Ï´Ù." << endl;

	}

	return false;
}

void Creature::Attack(Creature* const target)
{
	if(!CheckState()) return;

	cout << "\"" << _name << "ÀÇ °ø°Ý!\"" << endl;
	SOUND->PlayPlayerAttack();
	int damage = this->_atk + this->Crit(target->GetState());
	target->GetDamage(damage);

}

bool Creature::GetDamage(int atk)
{
	cout << "\"" << this->_name << "Àº/´Â " << atk << "¸¸Å­ÀÇ µ¥¹ÌÁö¸¦ ¹Þ¾Ò´Ù!";
	this->_hp -= atk;

	if (this->_hp <= 0)
	{
		cout << endl << "\"" << this->_name << " Àº€/´Â ¾²·¯Á³´Ù!\"" << endl;
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
		cout << "\"Å©¸®Æ¼ÄÃ!\"" << endl;
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
	else if (_state & (State::RUN)) cout << " (µµ¸Á°¨)";
	cout << endl;
}
