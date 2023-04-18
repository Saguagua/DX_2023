#include <iostream>

using namespace std;

//이동개념 (이사)
//-> 많이 쓰이진 않는다 -> 프레임워크 단계에서 많이 쓰인다.

class Pet
{
public:
private:
};


class Player
{
 public:
    Player() {_pet = new Pet();}
    ~Player() {delete _pet;}
    
 private:
    Pet* _pet;
};

//Call by Value
void PrintPlayerByVal(Player p)
{
    //원본 수정 안함
    //외부에서 오는 원본 수정 불가
    //p라는 애를 바꿔도 원본 영향 없다 
    //메모리 낭비 심하다
}
//Call by Ref
void PrintPlayerByRef(Player& p)
{
    //포인터 크기와 같은 바이트만큼 할당
    //값 전달 방법과 동일하게 사용
    //원본값 수정 가능
    //없는 값을 매개변수로 받기 불가능
    //값 전달과 형식이 같아 혼동이 올 수 있다
}
//Call by const Ref
void PrintPlayerByConRef(const Player& p)
{
    //메모리 절약
    //원본 수정 불가
}
//Call by Address
void PrintPlayerByAdd(Player* p)
{
    //원본 주소값 복사로 원본 접근 가능
    //nullptr 가능 - 없는 값 처리 가능
    //예외 처리가 필요하다
    //메모리 오염이 될 수 있다.
}

void PrintPlayerByRValueRef(Player&& p)
{
    
}

//lvalue
//-왼쪽에 있을 수 있는 변수
//- 수정이 가능한 변수
// 
//rvlaue
//- 수정이 불가능한 변수
//-lvalue가 될 수 없는 변수

int main()
{
    Player* p1 = new Player();
    Player* p2 = new Player(std::move(*p1));

    Player* p3 = new Player();

    p3 = std::move(p2);
    
}
