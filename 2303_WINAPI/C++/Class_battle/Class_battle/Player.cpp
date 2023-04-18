#include "Player.h"

Player::Player()
	:_hp(5)
{}

Player::~Player()
{
	cout << "플레이어 삭제" << endl;
}

void Player::Attack()
{
	cout << "Player의 공격" << endl;
}
