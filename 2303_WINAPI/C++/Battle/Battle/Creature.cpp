#include "framework.h"

using namespace std;

Creature::Creature()
{
	_hp = 0;
	_atk = 0;
	_name = "";
}

Creature::Creature(int hp, int atk, string name)
{
	_hp = hp;
	_atk = atk;
	_name = name;
}

//:: -> 범위지정연산자(소속연산자)
Creature::~Creature(){}

void Creature::PrintInfo()
{
	cout << _hp << endl;
	cout << _atk << endl;
	cout << _name << endl;
}
