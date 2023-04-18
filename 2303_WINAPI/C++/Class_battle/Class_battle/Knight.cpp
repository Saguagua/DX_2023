#include "Knight.h"

Knight::Knight()
{
	this->_hp = 15;
	this->_stamina = 10;
}

Knight::~Knight()
{
	cout << "나이트 삭제" << endl;
}

void Knight::Attack()
{
	cout << "Knight의 공격" << endl;
}
