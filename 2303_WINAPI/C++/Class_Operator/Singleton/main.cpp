#include <iostream>
#include "SoundManager.h"
using namespace std;
#define SOUND SoundManager::GetInstance()
//�̱��� ����
//Sound Manager �����
//1. ��𼭳� ���� ����
//2. ��ü�� ������ �� �ϳ��� ���� -> ������ �����ؾ���.
//3. ���� �ֱ�� ���α׷��Ӱ� ���� ���� (heap�� �Ҵ�)

static SoundManager* instance;

class Player
{
public :
	// ����Լ� ȣ�� ����
	// 1. �Ҽ�
	// 2. ��ü
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