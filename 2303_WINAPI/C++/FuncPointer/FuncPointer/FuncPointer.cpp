#include <iostream>

using namespace std;

//함수 포인터

//함수 시그니처 : 반환 타입, 매개 변수ㅡ 함수 이름

//전역함수
void PrintHello()
{
    cout << "Hello World!" << endl;
}

void PrintMySelf()
{
    cout << "안녕 나는 나야" << endl;
}

int AddInt(int a, int b)
{
    return a + b;
}

class Player
{
public:
    Player() : _fn(nullptr), _fn2(nullptr), _petfn(nullptr) {}
    ~Player() {}

    void SetFN(FN fn, FN2 fn2) { _fn = fn; _fn2 = fn2; }
    void PrintInfo()
    {
        if (_fn != nullptr)
            _fn();
    }
private:
    FN _fn;
    FN2 _fn2;
    FN3 _petfn;
};

class Pet
{
public:
    void Bark() { cout << "멍" << endl; }
};


// 함수 포인터의 선언 방법
//typedef : 타입 정의
typedef unsigned int UINT;
typedef void(*FN)(void);
typedef int(*FN2)(int, int);
typedef void(Pet::* FN3)(void);


int main()
{
#pragma region funcP
    UINT aUInt = 5;
    void (*fn)(void);
    fn = &PrintHello;
    FN fn2;
    fn2 = &PrintHello;

    fn();

    FN2 fn3 = &AddInt;
    cout << fn3(1, 2) << endl;
#pragma endregion

    Player* player = new Player();

    player->SetFN(&PrintHello, nullptr);
    player->PrintInfo();

    Pet* pet = new Pet();

    FN3 asdf = &Pet::Bark;
    (pet->*asdf)();

    delete pet;
    delete player;
    return 0;
}

