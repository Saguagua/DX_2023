#pragma once
// ���
// public ��� : �θ��� public -> public, protected -> protected, private�� ���� �� ����
// protected ��� : �θ��� public -> protected��
// private ��� : �θ��� public�� -> private
class Player : public Creature
{
public :
	Player();
	Player(int hp, int atk, string name);
};