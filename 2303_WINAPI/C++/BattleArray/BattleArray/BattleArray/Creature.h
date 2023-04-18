#pragma once
class Creature
{
public :
	Creature();

	unsigned char& GetState();
	int Crit(unsigned char& state) const;
	void Attack(Creature* const target);
	void GetDamage(int atk);
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

