#include "framework.h"
#include "Creature.h"

void Creature::SetInfo(int hp, int atk, string name)
{
    _hp = hp;
    _atk = atk;
    _name = name;
}

void Creature::PrintInfo()
{
    cout << "Name : " << _name << endl;
    cout << "HP : " << _hp << endl;
    cout << "ATK : " << _atk << endl;
}

void Creature::Attack(Creature& other)
{
    if (IsDead())
        return;

    cout << _name << "�� " << other._name << "�� ����!!!" << endl;
    other.TakeDamage(this->_atk);
}

void Creature::TakeDamage(int amount)
{
    if (IsDead())
        return;

    this->_hp -= amount;
    cout << this->_name << "��"<< amount <<"��ŭ ���ݹ޾ҽ��ϴ�!!!" << endl;
}

bool Creature::IsDead()
{
    bool result = _hp <= 0;

    if (result)
        cout << _name << "�� �׾����ϴ�." << endl;

    return result;
}
