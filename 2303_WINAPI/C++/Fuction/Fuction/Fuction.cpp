#include <iostream>

using namespace std;

// CPU
// - 연산장치
// - 제어장치/논리장치
// RAM
// - CPU에서 연산한 data를 저장
// - 물리적으로 HDD보다 가깝다.
// - 용량리 작다.
// - 저장한 것들이 휘발성
// HDD : help donkey dumbass
// - 물리적으로 멀어 저장, 불러오기 시간이 길다.
// 용량이 크다
// - 저장한 것들이 비영구적

// Stack 영역

int Add(int a, int b);

int Add(int a, int b, int c);

int Factorial(int numInt);

int Add(int a, int b, int c, int d, int e = 0);

int main() {
    int aInt = Factorial(5);//Add(1, 2, 3, 4, 5);
    srand(unsigned int(time(nullptr)));
    int randnum = rand() % 10 + 1;
    cout << randnum << endl;
    cout << aInt << endl;
}

int Factorial(int numInt) {

    if (numInt == 1) return 1;

    return numInt * Factorial(numInt - 1);
}

int Add(int a, int b) {
    int result = a + b;

    return result;
}

int Add(int a, int b, int c) {
    int result = 0;

    result = Add(a, b) + c;

    return result;
}

int Add(int a, int b, int c, int d, int e) {
    int result = 0;

    result = Add(a, b, c) + d + e;

    return result;
}