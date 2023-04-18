#include <iostream>

using namespace std;

// C스타일 캐스팅
// 자료형 따라 캐스팅할 때 안전/불안전
// int -> float 안전
// float -> int 불안전

// 크기에 따라 캐스팅할 때 안전/불안전
// short -> int (안전)
// int -> short (불안전) 

// 포인터 캐스팅
// Knight* pPtr = (Knight*)new Player(); // 다운캐스팅 -> 부모가 자식의 형태로 형변환 되는 것 (불가)
// => 명시적으로 형변환을 만들어주면 가능은 하나,,, 메모리 오염의 가능성이 있다.
// Player* kPtr = (Player*)new Knight(); // 업캐스팅 -> 자식이 부모로 형변환 되는 것

// 참조 캐스팅... 포인터 캐스팅과 동일하다.


// C++ 스타일 캐스팅 4총사
// static_cast<> 90%
//  - 논리적으로 괜찮은 캐스팅이면 OK, 통과 X
// const_cast<> 0.0001%
//  - const 붙은 객체를 떼거나 붙일 수 있다.
// dynamic_cast<> 9.999%
// - 상속관계에서만 쓴다.
// - 가상함수 테이블... 즉 RTTI 기능을 써서 실행 도중에 형변환을 시켜주는 얘
// => 가상함수 테이블이 꼭 있어야 쓸 수 있다.
// reinterpret_cast<> 0.01%
// - 땡깡피우는 얘

class Player
{
public:
	Player() : _hp(0) {}
	virtual ~Player() {}

	virtual void Attack() { cout << "PlayerAttack" << endl; }

public:
	int _hp;
};

class Knight : public Player
{
public:
	Knight() : _stamina(0) {}
	virtual ~Knight() {}

	virtual void Attack() override { cout << "KnightAttack!!!" << endl; }
	void Kick() { cout << "Kick!!!" << endl; }

public:
	int _stamina;
};

// 클래스, struct 캐스팅

int vInt;
int wInt = 5;

int main()
{
#pragma region C스타일 캐스팅
	int aInt = 5; // 0b 0111
	float aFloat = 0.5f; // 부호부(1) / 지수부(8)/ 유효숫자 (23) -> 32 = 4바이트

	aInt = (int)aFloat;

	cout << aInt << endl;

	Player* p1 = new Player();
	Player* k1 = new Knight();

	((Player&)(*k1))._hp = 5;
	((Knight*)(p1))->_stamina = 10; // 메모리 오염
#pragma endregion


	aInt = static_cast<int>(aFloat);
	Player* k2 = static_cast<Player*>(new Knight());
	
	int* aPtr = &aInt;
	// Player* k3 = static_cast<Player*>(&aInt);

	char* str = const_cast<char*>("Hello World"); // "문자열" -> 리터럴 상수

	Player* knight1 = new Knight();
	knight1->Attack();
	dynamic_cast<Knight*>(knight1)->Kick();


	Player* k3 = reinterpret_cast<Player*>(&aInt); // aInt주소를 그냥 Player*로 무조건 바꿔줘

	return 0;
}