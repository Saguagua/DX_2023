#include "framework.h"

void Archer::Skill(vector<Creature*> const v)
{
	cout << _name << "��/�� ȸ�Ǹ� ����ߴ�!" << endl;

	_miss = true;
}

bool Archer::GetDamage(int atk)
{
	if (_miss)
	{
		_miss = false;
		cout << _name << "��/�� ������ ȸ���߽��ϴ�!" << endl;
		return false;
	}



	return Creature::GetDamage(atk);
}
