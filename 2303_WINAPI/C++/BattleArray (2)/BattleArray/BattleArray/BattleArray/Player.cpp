#include "framework.h"

Player::Player(string name)
{
	this->_name = _name;
	this->_hp = 100;
	this->_atk = 10;
	this->_crit = 20;
	this->_state = 0;
}

void Player::Attack(Monster* const target)
{
	if (target->GetState() & (State::DEATH))
		return;
	else if (this->_state & State::DEATH)
		return;
	else if (this->_state & State::STUN)
	{
		cout << this->_name << "은/는 스턴 상태입니다." << endl << endl;
		this->_state = State::NORMAL;
		return;
	}

	cout << this->_name << "의 공격!" << endl;

	int damage = this->_atk + this->Crit(target->GetState());
	target->GetDamage(damage);

	return;
}

void Player::Heal()
{
	int healNum = rand() % 20 + 10;

	if (healNum + this->_hp > _MaxHp)
		healNum = _MaxHp - this->_hp;

	this->_hp += healNum;
	cout << this->_name << "은 " << healNum << "만큼 회복했다!" << endl << endl;

	Sleep(1000);
}

bool Player::Run() const
{
	bool runBool = rand() % 2;

	if (!runBool)
		cout << this->_name << "은 도망쳤다!" << endl << endl;
	else
		cout << this->_name << "은 도망에 실패했다!" << endl << endl;

	Sleep(1000);

	return runBool;
}