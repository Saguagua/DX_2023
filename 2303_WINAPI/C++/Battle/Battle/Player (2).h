#pragma once
// 상속
// public 상속 : 부모의 public -> public, protected -> protected
// protected 상속 : 부모의 public -> protected, 
// private 상속 : 부모의 public -> private
class Player : public Creature
{
public:
	Player();
	Player(int hp, int atk, string name);
	~Player();

};

