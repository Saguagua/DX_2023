#pragma once
#include "framework.h"

class Player :public Creature
{
public :
	Player(string _name);
	Player(string name, int hp, int atk, int crit);
	virtual void Attack(Creature* const target) override;
	virtual void Skill(vector<Creature*> const vector) = 0;
	bool MultipleAttack();
	void Heal();
	bool Run() const;
	int GetAtk() const;
};

