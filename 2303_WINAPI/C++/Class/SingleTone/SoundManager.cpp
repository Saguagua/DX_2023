#include "SoundManager.h"

SoundManager* SoundManager::_instance = nullptr; // static 멤버변수의 초기화
SoundManager::SoundManager()
{
	cout << "SoundManager 생성!!!" << endl;
	_playerSound = "Player 공격!!!!";
}

SoundManager::~SoundManager()
{
	cout << "SoundManager 삭제!!!" << endl;
}
