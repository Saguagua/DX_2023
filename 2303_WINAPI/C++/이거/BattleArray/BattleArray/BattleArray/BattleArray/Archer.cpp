#include "framework.h"

void Archer::Skill(vector<Creature*> const v)
{
	cout << _name << "은/는 회피를 사용했다!" << endl;

	_miss = true;
}

bool Archer::GetDamage(int atk)
{
	if (_miss)
	{
		_miss = false;
		cout << _name << "은/는 공격을 회피했습니다!" << endl;
		return false;
	}



	return Creature::GetDamage(atk);
}
