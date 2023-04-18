#include "framework.h"

int main()
{
	Creature creature = Creature(100,10,"Hanil");
	creature.PrintInfo();

	Player player = Player();
	player.PrintInfo();

	return 0;
}