#pragma once
// 穿号識情
class Monster; // 穿号識情

class Player : public Creature
{
public:
	Player();
	Player(int hp, int atk, string name);
	~Player();

	void Attack(Monster* monster);
};

