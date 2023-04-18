#include "framework.h"
#include "Player.h"

Player::Player()
: Creature() // ���� �ʱ�ȭ ���� 
{
}

Player::Player(int hp, int atk, string name)
: Creature(hp,atk,name) // �����ʱ�ȭ������ �ڱ� �ڽ��� ��������� �ʱ�ȭ �����ϴ�.
{
}

Player::~Player()
{
}

void Player::Attack(Monster* monster)
{
	monster->Damaged(_atk);
}
