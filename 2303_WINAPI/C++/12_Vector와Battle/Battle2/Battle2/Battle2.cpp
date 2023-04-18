#include "framework.h"

// 미리컴파일된 헤더 만들기
// 1. framework.h, framework.cpp
// 2. framework.h에 미리 컴파일할 내용 다 적기(ex #include <iostream>)
// 3. framework.cpp에서 #include "framework.h" 해주기
// 4. framework.cpp 속성 -> C/C++ -> 미리컴파일된 헤더, 만들기, 파일: framework.h
// 5. 프로젝트 속성 -> C/C++ -> 미리컴파일된 헤더, 사용, 파일 : framework.h

// 과제 1
// 1. player와 monster가 서로 공격하기
// 2. 둘중에 하나 죽을 때까지 서로 공격

int main()
{
	Player* player1 = new Player(100, 10, "Hanil");
	Monster* monster = new Monster(50, 15, "Monster");

	player1->Attack(monster);
	monster->PrintInfo();

	delete player1;
	delete monster;

	return 0;
}