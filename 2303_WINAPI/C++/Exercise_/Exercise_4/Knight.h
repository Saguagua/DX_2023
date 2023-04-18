#pragma once

class Knight
{
public:
	Knight();
	Knight(int hp);
	~Knight();

	void PrintInfo();

	void AddHp(int value);
	bool IsDead();

public:
	int _maxHp;
	int _hp; // 4바이트... -21억 ~ +21억...(-2^31 ~ 2^31 - 1)
	int _attack;
};

