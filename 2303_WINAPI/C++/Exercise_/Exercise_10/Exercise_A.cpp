#include <iostream>
#include <memory>
using namespace std;
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Pet.h"
#include "Arrow.h"
#include <vector>

// [Bug Report #10]
// 궁수라며면 자고로 화살을 쏴야겠죠.
// Arrow는 자신을 목표 대상물을 target으로 관리하고
// Arrow를 만들 때 설정한 데미지 만큼 target의 체력을 깎습니다.
// 테스트를 위해 화살 10개를 생성해서 기사를 피격했는데...
// C++이 늘 그렇지만 되는 일이 없고 또 크래시가 납니다.
// 뭐가 문제일까요?

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	shared_ptr<Archer> archer = make_shared<Archer>(new Pet());
	archer->_hp = 100;
	archer->_maxHp = 100;
	archer->_attack = 20;
	
	shared_ptr<Knight> knight = make_shared<Knight>();
	knight->_hp = 150;
	knight->_maxHp = 150;
	knight->_attack = 10;
	
	vector<shared_ptr<Arrow>> arrows;
	arrows.reserve(10);
	for (int i = 0; i < 10; i++)
	{
		// 기사를 타겟으로, 궁수의 공격력을 지닌 상태
		shared_ptr<Arrow> arrow = make_shared<Arrow>(knight, archer->_attack);
		arrows.push_back(arrow);
	}

	// 메모리관리 원칙
	// 1. 외부-외부/ 내부-내부
	// 2. Use After Free
	// 3. 삭제는 생성의 역순으로

	// 허상포인터 / Dangling Pointer
	// 삭제된 곳이나 엉뚱한 곳을 가리키고 있는 포인터

	for (int i = 0; i < 10; i++)
	{
		arrows[i]->AttackTarget();

		if (knight->IsDead())
		{
			cout << "죽었습니다." << endl;
			break;
		}
	}

}
