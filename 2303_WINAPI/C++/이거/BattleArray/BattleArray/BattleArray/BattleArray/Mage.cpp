#include "framework.h"

void Mage::Skill(vector<Creature*> const v)
{
	cout << _name << "��/�� ���� ���� ����ߴ�!" << endl;

	for (int i = 1; i < v.size(); i++)
		dynamic_cast<Player*>(v[i])->Heal();
}
