#include "framework.h"

void Creature::Attack(Creature* target)
{
	if (IsDead) return;

	cout << _name << "이 공격" << endl;
}

void Creature::TakeDamage(int amount)
{
	if (IsDead()) return;

	_hp -= amount;
	cout << _name << "이" << amount << "만큼 공격받음" << endl;
}

bool Creature::IsDead()
{
	if (_hp <= 0) return true;
	return false;
}
