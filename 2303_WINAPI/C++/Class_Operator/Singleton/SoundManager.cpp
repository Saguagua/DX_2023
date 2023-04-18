#include "SoundManager.h"

SoundManager* SoundManager::_instance = nullptr;

void SoundManager::Create()
{
	if (_instance == nullptr)
		_instance = new SoundManager();
}

void SoundManager::Delete()
{
	if (_instance != nullptr)
	{
		delete _instance;
		_instance = nullptr;
	}
}

SoundManager* SoundManager::GetInstance()
{
	if (_instance != nullptr)
		return _instance;
	else return nullptr;
}



SoundManager::SoundManager()
{
	this->_playerSound = "플레이어의 공격!";
}

SoundManager::~SoundManager()
{
}
