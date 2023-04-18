#include "framework.h"

void Creature::Attack(Creature* target)
{
	if (IsDead) return;

	cout << _name << "�� ����" << endl;
}

void Creature::TakeDamage(int amount)
{
	if (IsDead()) return;

	_hp -= amount;
	cout << _name << "��" << amount << "��ŭ ���ݹ���" << endl;
}

bool Creature::IsDead()
{
	if (_hp <= 0) return true;
	return false;
}
