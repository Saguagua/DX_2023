#include <iostream>
#include "SoundManager.h"
using namespace std;
#define SOUND SoundManager::GetInstance()
//싱글턴 패턴
//Sound Manager 만들기
//1. 어디서나 접근 가능
//2. 객체가 무조건 단 하나만 존재 -> 생성을 제어해야함.
//3. 생성 주기는 프로그래머가 설정 가능 (heap에 할당)

static SoundManager* instance;

class Player
{
public :
	// 멤버함수 호출 조건
	// 1. 소속
	// 2. 객체
	void Attack() { SOUND->PlayerSound();}
private :
};

int main()
{
	SoundManager::Create();
	Player player;
	player.Player::Attack();
	SoundManager::Delete();
	return 0;
}