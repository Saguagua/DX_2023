#include "framework.h"
#include "Creature.h"

Creature::Creature() // �����ʱ�ȭ�� ����� ���ÿ� �ʱ�ȭ�Ѵ�.
: _maxHp(100)// ��� ���� �ʱ�ȭ �������� �ʱ�ȭ�Ѵ�.
, _hp(0)
, _atk(0)
, _name("")
{
	// ���� �ʱ�ȭ
}

Creature::Creature(int hp, int atk, string name)
: _hp(hp)
, _atk(atk)
, _name(name)
, _maxHp(100)
{
}

Creature::~Creature()
{
}

// Creature�� ����Լ�
// :: -> ��������������(�Ҽӿ�����)
void Creature::PrintInfo()
{
	cout << _name << "�� ����!" << endl;
	cout << "HP : " << _hp << endl;
	cout << "ATK : " << _atk << endl;
}
