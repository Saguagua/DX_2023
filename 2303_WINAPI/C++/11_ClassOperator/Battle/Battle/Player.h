#pragma once
// ���漱��
class Monster; // ���漱��

class Player : public Creature
{
public:
	Player();
	Player(int hp, int atk, string name);
	~Player();

	void Attack(Monster* monster);
};

