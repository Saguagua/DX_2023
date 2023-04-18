#pragma once
// 상속
// public 상속 : 부모의 public -> public, protected -> protected, private는 받을 수 없음
// protected 상속 : 부모의 public -> protected로
// private 상속 : 부모의 public이 -> private
class Player : public Creature
{
public :
	Player();
	Player(int hp, int atk, string name);
};