#include "SoundManager.h"

SoundManager* SoundManager::_instance = nullptr; // static ��������� �ʱ�ȭ
SoundManager::SoundManager()
{
	cout << "SoundManager ����!!!" << endl;
	_playerSound = "Player ����!!!!";
}

SoundManager::~SoundManager()
{
	cout << "SoundManager ����!!!" << endl;
}
