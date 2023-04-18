#pragma once

class Creature
{
public:
	Creature();
	Creature(int hp, int atk, string name);
	~Creature();

	void PrintInfo();

protected:
	int _hp;
	int _atk;
	const int _maxHp;
	string _name;
};

