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

//�÷��̾���� ���� ��ų ����
// ����Ʈ�� ����
// �������� ���� ��
// ���Ĵ� 1ȸ Ȯ�� ȸ��
//������ ���� ���� �� ���� ������ �ö󰣴�