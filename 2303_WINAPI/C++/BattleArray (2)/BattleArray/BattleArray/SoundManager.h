#include "framework.h"
#pragma once
#define SOUND SoundManager::GetInstance()

class SoundManager
{
public:
	static void Create();
	static void Delete();
	static SoundManager* GetInstance();
	void PlayPlayerAttack();
	void PlayPlayerHeal();
	void PlayPlayerRun();
	void PlayMonsterAttack();
	void PlayPlayerDeath();
	void PlayMonsterDeath();
	void PlayCrit();
	void PlayStun();

private:
	static SoundManager* _instance;
	SoundManager();
	~SoundManager();
	string _playerAttack;
	string _playerHeal;
	string _playerRun;
	string _monsterAttack;
	string _playerDeath;
	string _monsterDeath;
	string _crit;
	string _stun;
};

