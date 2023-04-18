#include "framework.h"

Player::Player(string name)
	:Creature(name, 100, 10, 20)
{}

void Player::Attack(Creature* const target)
{
	if (target->GetState() & (State::DEATH))
		return;
	else if (this->_state & State::DEATH)
		return;
	else if (this->_state & State::STUN)
	{
		cout << "\"" << this->_name << "은/는 스턴 상태입니다.\"" << endl << endl;
		SOUND->PlayStun();
		this->_state = State::NORMAL;
		return;
	}

	cout << "\"" << _name << "의 공격\"" << endl;
	SOUND->PlayPlayerAttack();
	Creature::Attack(target);

	if (this->MultipleAttack())
	{
		cout << "\"더블 어택!\"" << endl;
		cout << "\"" << _name << "의 공격\"" << endl;
		SOUND->PlayPlayerAttack();
		Creature::Attack(target);
		if (target->IsDead()) return;
	}
	
	return;
}

bool Player::GetDamage(int atk)
{
	if (Creature::GetDamage(atk))
		SOUND->PlayPlayerDeath();
	return false;
}

bool Player::MultipleAttack()
{
	return rand() / 2;
}

void Player::Heal()
{
	int healNum = rand() % 20 + 10;

	if (healNum + this->_hp > _MaxHp)
		healNum = _MaxHp - this->_hp;

	this->_hp += healNum;
	cout << "\"" << this->_name << "은/는 " << healNum << " 만큼 회복했다!\"" << endl << endl;
	SOUND->PlayPlayerHeal();
	Sleep(1000);
}

bool Player::Run() const
{
	bool runBool = rand() % 2;

	if (!runBool)
	{
		cout << "\"" << this->_name << " 은/는 도망쳤다!\"" << endl << endl;
		SOUND->PlayPlayerRun();
	}
		
	else
		cout << "\"" << this->_name << " 도망에 실패했다.\"" << endl << endl;

	Sleep(1000);

	return runBool;
}