#include <iostream>

using namespace std;

// 함수포인터
// 함수 시그니쳐 : (반환형식) (함수이름) (매개변수)

// 전역함수
void PrintHello()
{
	cout << "Hello World!" << endl;
}

void PrintMySelf()
{
	cout << "안녕 내 이름은 한일이야!" << endl;
}

int AddInt(int a, int b)
{
	return a + b;
}

// 함수포인터의 선언 방법
// typedef : type definition
typedef unsigned int UINT;
typedef void(*FN)(void); // 전역함수를 담는 함수 포인터
typedef int(*FN2)(int, int);


// 콜백함수
class Pet
{
public:
	void Bark() { cout << "멍멍!!!" << endl; }
};

typedef void(Pet::* PETFN)(void);

class Player
{
public:
	Player() : _fn(nullptr), _petFN(nullptr) {}
	~Player() {}

	void SetFN(FN fn) { _fn = fn; }
	void SetPetFN(PETFN fn) { _petFN = fn; }

	void PrintInfo()
	{
		if (_fn != nullptr)
			_fn();
	}

	void PrintPet(Pet* pet)
	{
		if (_petFN != nullptr)
			(pet->*_petFN)();
	}

private:
	FN _fn;
	PETFN _petFN;
};

int main()
{
	UINT aUInt = 5;
	FN fn; // typedef를 이용한 함수포인터의 선언
	fn = &PrintHello;

	fn();

	FN2 fn2 = &AddInt;
	cout << fn2(1, 2) << endl;

	Player* player = new Player();

	player->SetFN(&PrintHello);
	player->PrintInfo();

	player->SetFN(&PrintMySelf);
	player->PrintInfo();

	// 멤버함수 포인터
	PETFN petFN = &Pet::Bark;

	Pet* pet = new Pet();

	// (pet->*petFN)();

	// pet한테 직접 Bark를 함수를 호출해준게 아니고
	// player로 하여금 Bark이라는 함수를 호출하게 했다.
	player->SetPetFN(&Pet::Bark);
	player->PrintPet(pet);

	delete pet;
	delete player;

	return 0;
}