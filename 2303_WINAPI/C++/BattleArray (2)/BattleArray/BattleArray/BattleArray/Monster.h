#pragma once
#include "framework.h"

class Player;

class Monster : public Creature
{
public :
	Monster();
	void Set(string _name, int _hp, int _atk, int _crit);
	void Attack(Player* const target);
};

