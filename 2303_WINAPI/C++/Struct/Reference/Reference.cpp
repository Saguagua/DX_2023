#include <iostream>

using namespace std;

// 과제
// 1. 여러분들의 struct 하나 만들기 (멤버: 3개이상)
// 2. SetInfo 하는 함수 3가지 만들기 (1. 주소전달, 2. 참조전달)
// 3. PrintInfo 하는 함수 3가지 만들기 (1. 주소전달, 2. 참조전달)

// 포인터 연산
// * : 간접연산자
// & : 주소연산자
// ++ : 증감연산자

// int* ptr... ptr++
// => +4된 주소값을 가르킨다.
// +4 - int

// int*
// 1. 타고 들어가면 int형이 있을 것이다.
// 2. 포인터연산할 때 int형의 크기만큼 뛰어건너 계산하겠다.

// nullptr
// 포인터를 쓸 수 없게 만들어준다... 초기화할 때 많이 쓰인다.

// 참조 : Reference
// int& aRef = aInt;
// (자료형)& 변수이름 = (초기화);

// c++ 관점			: 별명 짓기
// 어셈블리어 관점	: 포인터와 동일 동작

// Reference의 장점과 단점
// 장점
// 1. 쓰기 쉽다.

// 단점
// 1. 초기화할 때 없는 값(Null)로 초기화 될 수 없다.
// 2. 포인터 연산같은 작업을 수행할 수 없다.

// Pointer와 Reference의 공통점
//  1. 원본에 접근이 가능하다.
//  2. 둘다 어셈블리어 관점에서는 동일하게 동작한다.
//  3. 크기도 동일

struct Player
{
	float _hp;
	int _level;
	string _name;
};

// 1. Call by Value
//void PrintPlayer(Player value)
//{
//	cout << value._hp << endl;
//	cout << value._level << endl;
//	cout << value._name << endl;
//}
// 2. Call by Address
void PrintPlayer(const Player* const ptr)
{
	if (ptr == nullptr)
		return;

	cout << ptr->_hp << endl;
	cout << ptr->_level << endl;
	cout << ptr->_name << endl;
}

// 3. Call by Reference
// - 쓰기 쉽다.
// - null값을 참조할 일이 없다.

// Refence 읽기 전용
void PrintPlayer(const Player& reference)
{
	// reference._hp = 5;
	cout << reference._hp << endl;
	cout << reference._level << endl;
	cout << reference._name << endl;
}

void SetPlayer(Player* player, float hp, int level, string name)
{
	player->_hp = hp;
	player->_level = level;
	player->_name = name;
}

Player SetPlayer(Player player, float hp, int level, string name)
{
	player._hp = hp;
	player._level = level;
	player._name = name;

	return player;
}

int main()
{
	int aInt = 5;
	int* aPtr = nullptr;
	int& aRef = aInt;
	aPtr = &aInt;

	// (*aPtr)++;
	aRef++;
	cout << aInt << endl;

	Player player;
	player = SetPlayer(player, 50, 5, "hanil");
	//SetPlayer(&player, 100, 5, "hanil");
	// 1. value 방식 PrintPlayer(player)
	// 2. ref   방식 PrintPlayer(player) -> 함수 오버로딩 문제
	PrintPlayer(player);

	return 0;
}