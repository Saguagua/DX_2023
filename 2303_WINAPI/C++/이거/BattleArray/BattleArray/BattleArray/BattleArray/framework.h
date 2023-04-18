#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

enum Command
{
	SKILL = 0,
	ATTACK = 1,
	HEAL = 2,
	RUN = 3
};

enum State
{
	NORMAL = 0,
	DEATH = (1 << 0),
	STUN = (1 << 1),
	RUN = (1 << 2)
};

enum Class
{
	KNIGHT = 1,
	MAGE = 2,
	ARCHER = 3
};

#include "SoundManager.h"
#include "Creature.h";
#include "Monster.h";
#include "Boss.h"
#include "Player.h";
#include "Knight.h";
#include "Mage.h";
#include "Archer.h";

//플레이어들은 각자 스킬 존재
// 나이트는 도발
// 메이지는 광역 힐
// 아쳐는 1회 확정 회피
//보스는 스턴 당할 때 마다 내성이 올라간다