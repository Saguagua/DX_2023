#include "framework.h"
#include "Player.h"

Player::Player()
: Creature() //���� �ʱ�ȭ, ����� ���ÿ� �ʱ�ȭ�Ѵ�.
{
	//���� �ʱ�ȭ
	int _hp = 0;
	int _atk = 0;
	string _name = "";
}

Player::Player(int hp, int atk, string name)
: Creature(hp, atk, name)//_hp(hp) �Ұ���, ���� �ʱ�ȭ�� �ڱ� �ڽ��� �ɹ������� ȣ��
{
}
