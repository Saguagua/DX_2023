#pragma once

// ���漱��
class Monster;

class Player : public Creature
{
public:
	Player(int hp, int atk, string name);
	~Player();

	void Attack(Monster* monster);

private:
};

