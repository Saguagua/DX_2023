#pragma once
#include "framework.h"

class Player
{
public :
	Player();
	virtual ~Player();
	virtual void Attack();
protected:
	int _hp;
};

