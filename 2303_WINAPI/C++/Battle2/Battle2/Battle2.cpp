#include "framework.h"

int main()
{
	Creature player1 = Creature(100, 10, "JH");
	Creature monster = Creature(50, 3, "ASDF");
	Creature* ptr = &player1;
	player1.Attack();
	monster.Attack()
	
	return 0;
}