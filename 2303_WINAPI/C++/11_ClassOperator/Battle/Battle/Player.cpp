#include "framework.h"
#include "Player.h"

Player::Player()
: Creature() // 빠른 초기화 영역 
{
}

Player::Player(int hp, int atk, string name)
: Creature(hp,atk,name) // 빠른초기화영역은 자기 자신의 멤버변수만 초기화 가능하다.
{
}

Player::~Player()
{
}

void Player::Attack(Monster* monster)
{
	monster->Damaged(_atk);
}
