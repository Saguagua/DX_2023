#pragma once
#include "framework.h"

class Player :public Creature
{
public :
	Player(string _name);
	virtual void Attack(Creature* const target) override;
	virtual bool GetDamage(int atk) override;
	bool MultipleAttack();
	void Heal();
	bool Run() const;
};

