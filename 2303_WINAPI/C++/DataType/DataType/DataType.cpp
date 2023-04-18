#pragma region
// DataType.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 전처리기
// # 처리, 주석 처리
// 컴파일러
// 문법, 고수준 -> 저수준
//어셈블러
// 어셈블리어를 기계어로
// 링커
// - 라이브러리 결합
// - h, cpp 결합
#pragma endregion 컴파일 4단계

#include <iostream>
using namespace std;

int main()
{
    short a = 32766;
    cout << a;


    struct c {
        int a;
        short b;
    };
    c ca;

    ca.a = 1;
    ca.b = 2;
    cout << sizeof(c);

    return 0;
}
