#include "framework.h"

SoundManager* SoundManager::_instance = nullptr;

void SoundManager::Create()
{
	if (_instance == nullptr)
	{
		cout << "사운드 매니저 생성" << endl;
		_instance = new SoundManager();
	}
	
}

void SoundManager::Delete()
{
	if (_instance != nullptr)
	{
		cout << "사운드 매니저 삭제" << endl;
		delete _instance;
		_instance = nullptr;
	}
}

SoundManager* SoundManager::GetInstance()
{
	if (_instance != nullptr)
		return _instance;
	cout << "사운드 매니저가 없습니다." << endl;
	return nullptr;
}

void SoundManager::PlayPlayerAttack()
{
	cout << _playerAttack << endl;
}

void SoundManager::PlayPlayerHeal()
{
	cout << _playerHeal << endl;
}

void SoundManager::PlayPlayerRun()
{
	cout << _playerRun << endl;
}

void SoundManager::PlayMonsterAttack()
{
	cout << _monsterAttack << endl;
}

void SoundManager::PlayPlayerDeath()
{
	cout << _playerDeath << endl << endl;
}

void SoundManager::PlayMonsterDeath()
{
	cout << _monsterDeath << endl << endl;
}

void SoundManager::PlayCrit()
{
	cout << _crit << endl;
}

void SoundManager::PlayStun()
{
	cout << _stun << endl;
}

SoundManager::SoundManager()
	:_playerAttack("@@ Player attack sound @@"),
	_playerHeal("@@ Player heal sound @@"),
	_playerRun("@@ Player run sound @@"),
	_monsterAttack("@@ monster attack sound @@"),
	_playerDeath("@@ player death sound @@"),
	_monsterDeath("@@ monster death sound @@"),
	_crit("@@ critical sound @@"),
	_stun("@@ stun sound @@")
{}

SoundManager::~SoundManager()
{
}
