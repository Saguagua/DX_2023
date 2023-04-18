#pragma once
class Creature
{
public:
	Creature() : _hp(0), _atk(0), _name("") {}
	Creature(int hp, int atk, string name) : _hp(hp), _atk(atk), _name(name) {}
	~Creature() {}

	void SetInfo(int hp, int atk, string name);
	void PrintInfo();
	void Attack(Creature& other);
	void TakeDamage(int amount);

	bool IsDead();

	const string& GetName() const { return _name; }

protected:
	int _hp;
	int _atk;
	string _name;
};

