#include <iostream>

using namespace std;

#pragma region 기본 설명
//(자료형)* : 포인터 변수가 가리키는 곳을 찾아가보면 해당 자료형이 있을 것이라는 힌트를 준다.

// 연산자
// * : 간접연산자
//포인터 변수가 가리키는 곳으로 포탈타고 원본을 갖고온다.

// & : 주소연산자 해당 변수 주소값을 가져온다.
#pragma endregion

struct Player {
	int hp;
	int atk;
	string name;
};

void AddOne(int value);
void AddOne(int* value);
void PrintPlayerInfo(Player other);
void PrintPlayerInfo(const Player* const other);
void SetPlayerInfo(Player* const other, int hp, int atk, string name);
void SetNum(int& num);

int main()
{
#pragma region 정의
	int aInt = 1;
	int* aPtr = &aInt;

	*aPtr = 5;


	//cout << "aPtr 주소 " << &aInt << endl;
	//cout << "aPtr 가리키는 주소 " << aPtr << endl;
	//cout << "aPtr 값 " << *aPtr << endl;
#pragma endregion

#pragma region 함수 이용
	//cout << aInt << endl;
	//AddOne(&aInt);
	//cout << aInt;
#pragma endregion

	Player player;
	player.hp = 10;
	player.atk = 3;
	player.name = " 잡것";

	PrintPlayerInfo(player);
	int a = 1;
	SetNum(a);
	cout << a;
}


void AddOne(int value)
{
	value++;
}

void AddOne(int* value)
{
	(*value)++;
}

void PrintPlayerInfo(Player other)
{
	cout << "플레이어 이름 : " << other.name << endl;
	cout << "플레이어 HP : " << other.hp << endl;
	cout << "플레이어 atk : " << other.atk << endl;
}

// 무조건 4바이트 8바이트
// 수정이 가능
// 첫 const 는 other 내용물 바꾸지 못하게
// 두번째 const 는 other 자체가 가리키는 주소를 바꾸지 마라 (메모리 오염 방지)
// const 자료형 const 매개변수 - 읽기 전용(ReadOnly)
void PrintPlayerInfo(const Player* const other)
{
	cout << "플레이어 이름 : " << (*other).name << endl;
	cout << "플레이어 HP : " << (*other).hp << endl;
	cout << "플레이어 atk : " << (*other).atk << endl;
}

// . : 멤버연산자
//-> : 간접멤버연산자 *(변수).
void SetPlayerInfo(Player* const other, int hp, int atk, string name)
{
	other->name = name;
	other->hp = hp;
	other->atk = atk;

	PrintPlayerInfo(other);
}

void SetNum(int& num)
{
	num = 2;
	cout << num << endl;
}


