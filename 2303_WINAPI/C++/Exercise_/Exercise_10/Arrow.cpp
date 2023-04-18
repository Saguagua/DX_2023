#include "Arrow.h"
#include "Player.h"
#include <iostream>
#include <memory>

using namespace std;


Arrow::Arrow(shared_ptr<Player> target, int damage)
:_target(target), _damage(20)
{
	
}

Arrow::~Arrow()
{

}

void Arrow::AttackTarget()
{
	cout << "ȭ���� ���� �ǰ��մϴ�!" << endl;

	if (_target.lock()->IsDead())
		return;

	// ���� ����� �ִٸ�
	if (!_target.expired())
	{
		// �������� ������
		_target.lock()->AddHp(-_damage);
		_target.lock()->PrintInfo();
	}
}