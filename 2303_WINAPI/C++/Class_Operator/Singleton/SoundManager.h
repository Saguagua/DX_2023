#pragma once
#include <iostream>

using namespace std;

class SoundManager
{
public:
	static void Create();
	static void Delete();
	static SoundManager* GetInstance();
	void PlayerSound() { cout << _playerSound << endl; }
private:
	SoundManager();
	~SoundManager();
	string _playerSound;
	static SoundManager* _instance;
};

