#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <map>

using namespace std;

enum Command
{
	ATTACK = 1,
	HEAL = 2,
	RUN = 3
};

enum State
{
	NORMAL = 0,
	DEATH = (1 << 0),
	STUN = (1 << 1)
};

#include "SoundManager.h"
#include "Creature.h";
#include "Monster.h";
#include "Player.h";
