#include <iostream>
using namespace std;
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Pet.h"

// [Bug Report #9]
// 궁수가 죽으면 펫도 같이 죽는 사양이 추가되었습니다.
// 그런데 왜 프로그램도 같이 죽는걸까요?
// 이유를 찾아서 고쳐주세요!

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	// 메모리 관리
	// 1. 외부생성, 외부삭제/ 내부생성, 내부삭제
	// 2. Use After Free

	// 외부에서 생성한 것은 외부에서 지운다.
	Pet* pet = new Pet();
	Archer* archer = new Archer(pet);
	archer->_hp = 100;
	archer->_maxHp = 100;
	archer->_attack = 20;

	Knight* knight = new Knight();	
	knight->_hp = 150;
	knight->_maxHp = 150;
	knight->_attack = 100;
	
	int damage = knight->GetAttackDamage();
	archer->AddHp(-damage); // 아처가 죽을 때 Pet을 삭제한다.(X)

	delete archer;
	delete knight;
	delete pet;
}
