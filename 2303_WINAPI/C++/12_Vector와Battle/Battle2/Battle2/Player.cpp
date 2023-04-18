#include "framework.h"
#include "Player.h"

Player::Player(int hp, int atk, string name)
: Creature(hp,atk,name)
{
}

Player::~Player()
{
}

void Player::Attack(Monster* monster)
{
    if (IsDead())
        return;

    cout << _name << "�� " << monster->GetName() << "�� ����!!!" << endl;
    if (_hp < 30)
    {
        monster->TakeDamage(this->_atk * 2);
        return;
    }

    monster->TakeDamage(this->_atk);
}
