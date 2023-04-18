#pragma once
#include <iostream>

using namespace std;

class SoundManager
{
public:
	// static 멤버함수를 호출하기 위한 필요조건
	// 1. 소속
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new SoundManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
		{
			delete _instance;
			_instance = nullptr;
		}
	}

	static SoundManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
		return nullptr;
	}

	void PlayerSound() { cout << _playerSound << endl; }
	void PlayerSound(string name) { cout << name << "의 " << _playerSound << endl; }

private:
	SoundManager();
	~SoundManager();

	string _playerSound;
	string _monsterSound;
	static SoundManager* _instance;
};

