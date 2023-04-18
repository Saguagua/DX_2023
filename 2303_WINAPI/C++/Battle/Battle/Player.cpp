#include "framework.h"
#include "Player.h"

Player::Player()
: Creature() //빠른 초기화, 선언과 동시에 초기화한다.
{
	//늦은 초기화
	int _hp = 0;
	int _atk = 0;
	string _name = "";
}

Player::Player(int hp, int atk, string name)
: Creature(hp, atk, name)//_hp(hp) 불가능, 빠른 초기화는 자기 자신의 맴버변수만 호출
{
}
