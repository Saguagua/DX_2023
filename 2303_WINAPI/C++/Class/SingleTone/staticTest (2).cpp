#include <iostream>

using namespace std;

// 정적변수
// Data
// - 전역 변수
// - 정적 변수 :
// 컴퓨터 프로그래밍에서 동적/정적이란
// - 동적 : 실행 중에 뭔가 확인하거나 바꿀 수 있는 얘
// - 정적 : 프로그램 시작할 때 뭔가 일어난다.

// 정적변수
// - 프로그램 내에서 단 하나만 존재
// - 프로그램 시작할 때 할당, 프로그램이 종료될 때 삭제

int aInt = 5;
static int bInt = 10;

class Marine
{
public:

	void PrintAtk()
	{
		cout << _atk << endl;
	}

public:
	int aInt = 5;
	static int _atk;
};

int Marine::_atk = 3;

int staticTest()
{
	Marine arr[100];

	for (int i = 0; i < 100; i++)
	{
		arr[i].PrintAtk();
	}

	Marine::_atk++;

	for (int i = 0; i < 100; i++)
	{
		arr[i].PrintAtk();
	}

	return 0;
}