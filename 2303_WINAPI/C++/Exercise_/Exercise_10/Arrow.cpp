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
	cout << "화살이 적을 피격합니다!" << endl;

	if (_target.lock()->IsDead())
		return;

	// 공격 대상이 있다면
	if (!_target.expired())
	{
		// 데미지를 입힌다
		_target.lock()->AddHp(-_damage);
		_target.lock()->PrintInfo();
	}
}