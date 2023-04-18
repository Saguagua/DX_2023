#include "framework.h"
#include "Creature.h"

Creature::Creature() // 빠른초기화는 선언과 동시에 초기화한다.
: _maxHp(100)// 상수 빠른 초기화 영역에서 초기화한다.
, _hp(0)
, _atk(0)
, _name("")
{
	// 늦은 초기화
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

// Creature의 멤버함수
// :: -> 범위지정연산자(소속연산자)
void Creature::PrintInfo()
{
	cout << _name << "의 정보!" << endl;
	cout << "HP : " << _hp << endl;
	cout << "ATK : " << _atk << endl;
}
