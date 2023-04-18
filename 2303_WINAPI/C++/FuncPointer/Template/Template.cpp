#include <iostream>

using namespace std;

// 템플릿 : 주조틀
// 
// 함수 템플릿
template <class T = int>
T Add(T a, T b)
{
    return a + b;
}

float Add(float a, float b)
{
    return a + b;
}

int main()
{
    int aInt = Add(1, 2);
    float aFloat = Add<float>(2.2f, 3.5);

    std::cout << aFloat;
}
