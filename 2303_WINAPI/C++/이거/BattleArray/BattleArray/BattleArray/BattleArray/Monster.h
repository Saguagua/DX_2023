#pragma once
#include "framework.h"

class Player;

class Monster : public Creature
{
public :
	Monster(string name, int hp, int atk, int crit);
	void Set(string _name, int _hp, int _atk, int crit = 0);
	virtual void Attack(Creature* const target) override;
};

