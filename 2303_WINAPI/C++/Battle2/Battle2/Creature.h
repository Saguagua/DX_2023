#pragma once
class Creature
{
public:
	Creature() : _hp(0), _atk(0), _name("") {}
	Creature(int hp, int atk, string name) : _hp(hp), _atk(atk), _name(name) {}
	~Creature() {}

	void Attack(Creature* target);
	void TakeDamage(int amount);
	bool IsDead();

private :
	int _hp;
	int _atk;
	string _name;

};

