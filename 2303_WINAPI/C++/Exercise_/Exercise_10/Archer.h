#pragma once
#include "Player.h"
#include <memory>

class Archer : public Player
{
public:
	Archer(class Pet* pet);
	Archer(int hp);
	~Archer();

public:
	class Pet* _pet;
};

