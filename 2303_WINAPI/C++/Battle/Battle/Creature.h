#pragma once

using namespace std;

class Creature
{
public :
	Creature();
	Creature(int hp, int atk, string name);
	~Creature();

public :
	void PrintInfo();

protected:
	int _hp;
	int _atk;
	string _name;
};