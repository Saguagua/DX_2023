#include <iostream>

using namespace std;

//객체지향 3속성
//1. 은닉성
//- 접근지정자 : public, private, protected
//- public : 모든곳에서 접근 가능
//- private : 자기 자신의 함수에서만 접근 가능 (예외처리가 더 쉬워진다.)
//- protected : 자기 자신의 함수 혹은, 자식에서 접근 가능

//2. 상속성
//- 부모의 속성과 기능을 물려받는 자식을 만들 수 있다.
//-> 코드의 재사용성 증가.
//- is a 관계 성립이 되야함.

//3. 다형성
//- 함수 오버로딩
// 연산자 오버로딩 : 
//- 함수 오버라이딩
//-> 함수 재정의할 때 시그니쳐는 동일

class Car
{

public:
    Car()
    {
        _engine = 0;
        _handle = 0;
        _doors = 0;
        _wheels = 0;
    }

    Car(int engine, int handle, int doors, int wheels)
    {
        _engine = engine;
        _handle = handle;
        _doors = doors;
        _wheels = wheels;
    }
public:
    void PrintCarInfo()
    {
        cout << "car 속성" << endl;
        cout << _engine << endl;
        cout << _handle << endl;
        cout << _doors << endl;
        cout << _wheels << endl;
    }

    void SetEngine(int engine) {
        if (engine < 0) return;
        _engine = engine;
    }

protected:
    int _engine;
    int _handle;
    int _doors;
    int _wheels;

};

class SuperCar : public Car
{
public :
    SuperCar()
    {
        _engine = 2;
        _handle = 1;
        _doors = 2;
        _wheels = 4;
    }
private :
};

int main()
{
    Car car = Car(1, 1, 4, 4);
    SuperCar sCar = SuperCar();

    car.PrintCarInfo();
    sCar.PrintCarInfo();

    return 0;
}