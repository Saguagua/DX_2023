#include <iostream>

using namespace std;

#include "SoundManager.h"

#define SOUND SoundManager::GetInstance()

// �̱��� ���� �����
// Sound Manager �����
// 1. ��𼭳� ���� ����
// 2. ��ü�� ������ �� �ϳ��� ���� -> ������ �����ؾ��Ѵ�.
// 3. �����ֱ⸦ ���α׷��� ������ �� �ֵ���

// �̱��� ����
// ������ ����...... ���α׷����� �� �����

// - ������Ʈ ����
// - ������, ������ ����

// �̱����� Data�������� �׳� �Ҵ��ϴ� �ȵɱ�?
// Data, Stack�� ���α׷� ������ �Ҵ緮�� �����ش�.
// -> ���۵� �� �Ҵ�, ������ ������ �� ����
// => Data�� Statck������ �Ҵ��ϴ� ���� �ִ��� �����Ѵ�.

class Player
{
public:
	// ���
	// ����Լ� ȣ�� ����
	// 1. �Ҽ�
	// 2. ��ü
	void Attack() { SOUND->PlayerSound("����"); }
private:
	// �Ӽ�
};

int main()
{
	SoundManager::Create();
	
	Player player;
	player.Attack();

	SoundManager::Delete();

	return 0;
}