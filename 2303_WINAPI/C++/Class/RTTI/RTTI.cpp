#include <iostream>

using namespace std;

// RTTI (RealTime Time Information)
// vftable (vftable가리키는 포인터가 맨 앞자리 주소에 추가된다.)
// => 가상함수(virtual function)가 한 개 이상 존재해야한다.

class Player
{
public:
	Player() : _hp(5) { cout << "Player 생성" << endl; }
	virtual ~Player() { cout << "Player 삭제" << endl; }

	virtual void Attack() { cout << "Player의 Attack!!!" << endl; }

protected:
	int _hp;
};

class Knight : public Player
{
public:
	Knight() : _stamina(10) 
	{
		_hp = 15;
		cout << "Knight 생성" << endl; 
	}
	virtual ~Knight() { cout << "Knight 삭제" << endl; }

	virtual void Attack() override { cout << "Knight의 Attack!!!" << endl; }

private:
	int _stamina;
};

int main()
{
	Player* p1 = new Player();
	Player* k1 = new Knight(); // 업캐스팅

	p1->Attack();
	k1->Attack();

	delete p1;
	delete k1; // 2층 knight 소멸자 호출 되고, 1층 player 소멸자 호출

	return 0;
}