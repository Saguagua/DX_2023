#pragma once
#include "framework.h"

class Archer : public Player
{
public:
	Archer(string name, int hp, int atk, int crit) : Player(name, hp, atk, crit+20) {}
	// Player을(를) 통해 상속됨
	virtual void Skill(vector<Creature*> const target) override;
	virtual bool GetDamage(int atk) override;
private:
	bool _miss = false;
};

