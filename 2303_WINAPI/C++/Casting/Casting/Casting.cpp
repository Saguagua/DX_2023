#include <iostream>

using namespace std;

// C스타일 캐스팅
// int -> float 안전
// float -> int 소수점 없어진다.
// short -> int 안전
// int -> short 불안전

//static_cast<> 
//- 논리적으로 괜찮은 캐스팅이면 통과
//const_cast<>
//- cast 붙이거나 땔 수 있다.
//dynamic_cast<>
//- 상속 관계에서 사용하는 친구야. 업캐스팅 할 때, 자식의 함수를 사용하기 위해 사용해
//- 가상 함수 테이블 - RTTI 기능을 사용해 형변환 시켜준다
// 즉, 가상함수 테이블이 필수다!
//reinterpret_cast<>
//억지로 바꾸기
//

class Player
{
public:

public:
	int _hp;
};

class Knight : public Player
{
public:

public:
	int _stamin;
};

int main()
{
	int aInt = 5;
	float aFloat = 0.0f;

	aFloat = (float)aInt;

	cout << aInt << endl;

	Player p = Player();
	Knight k = Knight();

	p = k;//업캐스팅
	
	//k = p;//다운캐스팅

	Player* ptr1 = new Knight(); // 업캐스팅
	//Knight* ptr2 = new Player(); // 다운 캐스팅

	//참조 캐스팅 - 포인터 캐스팅과 동일.
	Player* p1 = new Player();
	Player* k1 = new Knight();

	((Player&)(*k1))._hp = 5;

	aInt = static_cast<int>(aFloat);
	Player* k2 = static_cast<Player*> (new Knight());

	int* aPtr = &aInt;
	Player* k3 = (Player*)&aInt; //결국 주소값이니 바꿀 수 있어 위험
	
	return 0;
}