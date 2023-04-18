
#include <iostream>

using namespace std;

//어셈블리어 : 포인터와 레퍼런스는 완전 동일 작업

//ref와 ptr 차이
// 1. ptr은 nullptr 받을 수 있다.
// ref는 별칭이기 때문에 nullptr 참조할 수 없다.
// 2. 선언만 남겨둘 수 없다.
// ref는 별징이기 때문에 반드시 참조할 누군가가 있어야한다.
// 
//ref와 ptr 공통점
//1. 어셈블리어상 동일 작업
//2. 원본 접근
// 
//참조 쓰는 이유
//1. 편하다
//2. 예외처리가 더 편함, 안정성이 더 높다.
//
//ptr 쓰는 이유
//1. nullptr 사용가능
//2. ref는 Call By value 랑 혼동 일으킬 수 있다. => const & (ReadOnly)
//3. 포인터 연산 가능

struct Player
{
    int hp;
    int atk;
    string name;
};

void PrintPlayer(const Player& player);
void SetPlayer(Player& const player, string name, int hp, int atk);

int main()
{
#pragma region 참 포
    int aInt = 3;
    int* ptr = &aInt; // 포인터
    int* ptr2;
    int& ref = aInt;  //참조

    ref = 5;
    *ptr = 5;

    //cout << aInt << endl;
#pragma endregion
    Player player;
    player.name = "a";
    player.hp = 100;
    player.atk = 20;

    SetPlayer(player, "a", 100, 20);
    PrintPlayer(player);
}

void PrintPlayer(const Player& player)
{
    cout << player.name << endl;
    cout << player.hp << endl;
    cout << player.atk << endl;
}

void SetPlayer(Player& const player, string name, int hp, int atk)
{
    player.name = name;
    player.hp = hp;
    player.atk = atk;
}
