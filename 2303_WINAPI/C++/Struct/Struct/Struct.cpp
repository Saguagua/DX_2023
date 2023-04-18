#include <iostream>

using namespace std;

// struct
// 구조체
// 사용자 정의 자료형

// 구조체의 크기 : 구조체 안의 있는 변수들의 자료형에 따라 결정된다.
// 저장되는 순서 : 비슷한 위치에 읽는 순서대로 같이 저장된다.

// 함수 오버로딩

struct Player
{
	// 멤버 변수
	// 구조체의 속성을 나타낸다.
	float _hp;
	int _level;
	string _name;
};

// 연산자 .
// . : 멤버연산자
// 해당 구조체의 멤버에 접근할 수 있게 해주는 연산자
// -> : 간접멤버연산자... (*포인터변수). == 포인터변수->

void PrintPlayer(Player player)
{
	// main								PrintPlayer
	// [][반환주소값][hanil(8바이트)] [Player player(8바이트)][반환주소값][]

	player._hp = 5;
	cout << player._hp << endl;
	cout << player._level << endl;
	cout << player._name << endl;
}

// (1. const) Player* (2. const) player
// 1. player 포인터에 포탈타고 가서 바꾸지마라
// 2. player 포인터 자체를 바꾸지말라

// => 매개변수가 읽기전용이다.
void PrintPlayer(const Player* const player)
{
	// main								PrintPlayer
	// [][반환주소값][hanil(8바이트)] [Player* player(4바이트)][반환주소값][]

	// player++;

	cout << player->_hp << endl;
	cout << player->_level << endl;
	cout << player->_name << endl;
}

// 매개변수 전달방식
// 1. 값전달... Call By Value
// - 함수 내부에서 값을 바꿔도 원본이 바뀌지 않는다.
// - 매개변수 넘길 때 새로 복사해서 만들기 때문에 구조체의 크기만큼 바이트가 할당

// 2. 주소전달... Call By Address
// - 함수 내부에 매개변수로 전달받은 주소값으로 포탈을 타서 '원본'을 수정할 수 있다.
// - 크기가 무조건 4바이트 혹은 8바이트로 고정

// ! . 

int main()
{
	Player hanil;
	hanil._hp = 100.0f;
	hanil._level = 10;
	hanil._name = "한일";

	PrintPlayer(&hanil);

	cout << hanil._hp << endl;

	return 0;
}