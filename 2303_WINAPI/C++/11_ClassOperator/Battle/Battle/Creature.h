#pragma once

class Creature
{
public:
	Creature();
	Creature(int hp, int atk, string name);
	~Creature();

	void PrintInfo();

	void Damaged(int amount);
	int& GetHp() { return _hp; }

protected:
	int _hp;
	int _atk;
	const int _maxHp;
	string _name;
};

