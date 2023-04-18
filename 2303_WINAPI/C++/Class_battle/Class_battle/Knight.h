#pragma once
#include "framework.h"

class Knight :public Player
{
public :
	Knight();
	virtual ~Knight() override;
	virtual void Attack() override;

private:
	int _stamina;
};

