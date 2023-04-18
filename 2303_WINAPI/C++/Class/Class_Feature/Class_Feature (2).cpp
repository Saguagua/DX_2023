#include <iostream>

using namespace std;

// 객체지향의 3속성
// 1.은닉성(캡슐화)
// - 접근지정자 : public, private, protected
// - public : 모든곳에서 접근할 수 있게 해준다.
// - private : 자기 자신의 함수에서만 접근할 수 있게해준다.
// - protected : 자기 자신의 함수 혹은, 자식에서 접근 가능하게 해준다.

// private 영역은 멤버함수만 접근할 수 있다.
// => 예외처리,

// 2. 상속성
// - 부모의 속성과 기능을 물려받는 자식을 만들 수 있다.
// => 코드의 재사용성이 증가한다.
// - is a 관계가 성립이 되야한다.
// SuperCar is a Car (O)
// Car is a SuperCar (X)
// - 부모의 속성 중에 protected, public 접근지정자를 쓴 멤버변수만 가져올 수 있다.

// 3. 다형성(형태가 다양하다.)
// - 함수 오버로딩
//   (연산자 오버로딩)
// - 함수 오버라이딩
// => 함수 재정의
// => 함수 재정의할 때 함수시그니쳐는 동일하다.

class Car
{
public:
	Car() // 다른 생성자가 없을 경우 암시적으로 생성
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

	// 연산자 오버로딩
	//Car operator+(const Car& other)
	//{
	//	_engine += other._engine;
	//	_handle += other._handle;
	//	_doors += other._doors;
	//	_wheels += other._wheels;
	//}

	// 멤버함수
	void PrintCarInfo()
	{
		cout << "Car에 대한 속성입니다." << endl;
		cout << _engine << endl;
		cout << _handle << endl;
		cout << _doors << endl;
		cout << _wheels << endl;
	}

	void SetEngine(int engine)
	{
		if (engine < 0)
			return;

		_engine = engine;
	}
	void SetCar(int engine) { _engine = engine; }
	void SetCar(double engine) { _engine = engine; }
	void SetCar(int engine, int handle) { _engine = engine; _handle = handle; }

protected:
	int _engine;
	int _handle;
	int _doors;
	int _wheels;
};

class SuperCar : public Car
{
public:
	SuperCar()
	{
		_engine = 2;
		_handle = 1;
		_doors = 2;
		_wheels = 4;
	}

	void PrintCarInfo()
	{
		cout << "SuperCar에 대한 속성입니다." << endl;
		cout << _engine << endl;
		cout << _handle << endl;
		cout << _doors << endl;
		cout << _wheels << endl;
	}

private:

};

int main()
{
	Car car = Car(1, 1, 4, 4);

	car.PrintCarInfo();

	SuperCar sCar = SuperCar();
	
	car.Car::PrintCarInfo();
	sCar.Car::PrintCarInfo();

	int aInt = 1;
	int bInt = 2;
	int cInt = aInt + bInt;

	Car car2 = Car();
	// Car car3 = car + car2;

	return 0;
}