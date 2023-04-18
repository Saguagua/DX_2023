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
		cout << "\"" << this->_name << "Àº€/´Â ½ºÅÏ »óÅÂÀÌ´Ù\"" << endl << endl;
		SOUND->PlayStun();
		this->_state = State::NORMAL;
		return;
	}

	cout << "\"" << _name << "ÀÇ °ø°Ý\"" << endl;
	SOUND->PlayPlayerAttack();
	int damage = this->_atk + this->Crit(target->GetState());
	target->GetDamage(damage);

	if (this->MultipleAttack() && !(target->IsDead()))
	{
		cout << "\"¿¬¼Ó °ø°Ý!\"" << endl;
		cout << "\"" << _name << "ÀÇ °ø°Ý!\"" << endl;
		SOUND->PlayPlayerAttack();
		int damage = this->_atk + this->Crit(target->GetState());
		target->GetDamage(damage);
	}

	return;
}

bool Player::GetDamage(int atk)
{
	cout << "\"" << this->_name << "Àº€/´Â " << atk << "¸¸Å­ÀÇ µ¥¹ÌÁö¸¦ ¹Þ¾Ò´Ù\"";
	this->_hp -= atk;

	if (this->_hp <= 0)
	{
		cout << endl << "\"" << this->_name << " Àº/´Â ¾²·¯Á³´Ù!\"" << endl;
		this->GetState() = State::DEATH;
		SOUND->PlayPlayerDeath();
		Sleep(1000);
		return true;
	}

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
	cout << "\"" << this->_name << "Àº€/´Â " << healNum << "¸¸Å­ È¸º¹Çß´Ù!\"" << endl << endl;
	SOUND->PlayPlayerHeal();
	Sleep(1000);
}

bool Player::Run() const
{
	bool runBool = rand() % 2;

	if (!runBool)
	{
		cout << "\"" << this->_name << " Àº€/´Â µµ¸ÁÃÆ´Ù!\"" << endl << endl;
		SOUND->PlayPlayerRun();
	}
		
	else
		cout << "\"" << this->_name << "Àº/´Â µµ¸Á¿¡ ½ÇÆÐÇß´Ù.\"" << endl << endl;

	Sleep(1000);

	return runBool;
}