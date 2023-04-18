#pragma once
#include "framework.h"

class Knight : public Player
{
public:
	Knight(string name, int hp, int atk, int crit) : Player(name, hp + 20, atk, 0) {}
	// Player을(를) 통해 상속됨
	virtual void Skill(vector<Creature*> const target) override;

};

