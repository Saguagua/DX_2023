#pragma once
#include "framework.h"

class Knight : public Player
{
public:
	Knight(string name, int hp, int atk, int crit) : Player(name, hp + 20, atk, 0) {}
	// Player��(��) ���� ��ӵ�
	virtual void Skill(vector<Creature*> const target) override;

};

