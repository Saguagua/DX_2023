#pragma once
#include "framework.h"

class Creature
{
public :
	Creature();
	Creature(string name, int hp, int atk, int crit);

	unsigned char& GetState();
	bool CheckState();
	virtual void Attack(Creature* const target);
	virtual bool GetDamage(int atk);
	int Crit(unsigned char& state) const;
	bool IsDead() const;

	void PrintInfo() const;

protected :
	string _name;
	int _hp;
	int _atk;
	int _crit;
	unsigned char _state;
	const int _MaxHp;
};

