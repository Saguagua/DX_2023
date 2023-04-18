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
	Creature::Attack(target);

	return;
}
