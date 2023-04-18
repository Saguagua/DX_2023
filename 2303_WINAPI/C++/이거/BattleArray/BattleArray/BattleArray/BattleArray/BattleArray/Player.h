#pragma once
#include "framework.h"

class Player :public Creature
{
public :
	Player(string _name);
	void Attack(Monster* const target);
	void Heal();
	bool Run() const;
};

