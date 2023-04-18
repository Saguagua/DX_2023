#include <iostream>

using namespace std;

//정적변수
//Data 영역
//- 전역 변수 : 
//- 정적 변수 : 어디서 선언하든 Data영역에 저장된다.
// -프로그램 내 단 하나만 존재
// - 시작시 생성, 종료시 삭제
//컴퓨터 프로그램의 동적 - 실행 중 뭔가 변경 가능, 정적 - 실행 중 뭔가 생성

int aInt = 5;
static int bInt = 10;

class Marine
{
public :

    void PrintAtk()
    {
        cout << _atk << endl;
    }

public :
    static int _atk;
};

int Marine::_atk = 3;

int staticTest()
{
    Marine::_atk = 4;

    Marine arr[100];

    for (int i = 0; i < 100; i++)
    {
        arr[i].PrintAtk();
    }

    Marine::_atk++;

    return 0;
}