#include <iostream>

using namespace std;

#include "SoundManager.h"

#define SOUND SoundManager::GetInstance()

// 싱글턴 패턴 만들기
// Sound Manager 만들기
// 1. 어디서나 접근 가능
// 2. 객체가 무조건 단 하나만 존재 -> 생성을 제어해야한다.
// 3. 생성주기를 프로그래머 설정할 수 있도록

// 싱글턴 패턴
// 디자인 패턴...... 프로그래밍할 때 방법론

// - 컴포넌트 패턴
// - 리스너, 관찰자 패턴

// 싱글턴을 Data영역에다 그냥 할당하는 안될까?
// Data, Stack은 프로그램 시작할 할당량을 정해준다.
// -> 시작될 때 할당, 삭제는 종료할 때 삭제
// => Data나 Statck영역에 할당하는 것을 최대한 지양한다.

class Player
{
public:
	// 기능
	// 멤버함수 호출 조건
	// 1. 소속
	// 2. 객체
	void Attack() { SOUND->PlayerSound("한일"); }
private:
	// 속성
};

int main()
{
	SoundManager::Create();
	
	Player player;
	player.Attack();

	SoundManager::Delete();

	return 0;
}