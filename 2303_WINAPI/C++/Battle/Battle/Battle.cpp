#include "framework.h"

//파일분할
//h. 는 선언용 파일
//.cpp 는 정의 및 실행파일

//미리 컴파일된 헤더(pch : pre compiled header)
//1. framework.h, framework.cpp 만들기
//2. framework.cp에서 #include "framework.h"
//3. framework.cpp 속성 (C/C++ -> 미리컴파일된 헤더 -> 미리컴파일된 헤더 만들기, framework.h)
//4. 프로젝트 속성(C/C++ -> 미리컴파일된 헤더 -> 미리컴파일된 헤더 사용, framework.h)

int main()
{
	Creature creature = Creature(100, 10, "Hun");
	creature.PrintInfo();

	Player player = Player();
	player.PrintInfo();

	return 0;
}
