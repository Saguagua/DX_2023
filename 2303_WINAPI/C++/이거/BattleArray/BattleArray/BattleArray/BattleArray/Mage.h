#pragma once
#include "framework.h"

class Mage : public Player
{
public:
	Mage(string name, int hp, int atk, int crit) : Player(name, hp, atk, crit) {}
	// Player을(를) 통해 상속됨
	virtual void Skill(vector<Creature*> const target) override;
};

