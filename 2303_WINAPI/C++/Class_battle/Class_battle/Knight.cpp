#include "Knight.h"

Knight::Knight()
{
	this->_hp = 15;
	this->_stamina = 10;
}

Knight::~Knight()
{
	cout << "����Ʈ ����" << endl;
}

void Knight::Attack()
{
	cout << "Knight�� ����" << endl;
}
