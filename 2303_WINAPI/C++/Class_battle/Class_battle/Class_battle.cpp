#include "framework.h"

int main()
{
	Player* p = new Player();
	Knight* k = new Knight();

	p->Attack();
	k->Attack();

	delete p;
	delete k;
}