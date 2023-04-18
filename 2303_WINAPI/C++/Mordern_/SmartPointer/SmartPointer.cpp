#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;

//스마트 포인터 : 메모리를 자동으로 관리


class Player
{
public:
    Player() {cout << "Player 생성" << endl; }
    Player(int value) {cout << "Player의 타입변환 생성자 호출" << endl; }
    ~Player() {cout << "Player 삭제" << endl; }

    void Print() {cout << "Player Print " << endl; }

    void SetTarget(shared_ptr<Player> other) {_target = other;}

    void Attack()
    {
        
        if (!_target.expired())
        {
            _target.lock()->_hp = 1;
            cout << "공격" << endl;
        }
    }

private:
    weak_ptr<Player> _target;
    int _hp = 5;
};

struct RefCountBlock
{
    int refCount = 1;
};

template <typename T>
class SharedPtr
{
public:
    SharedPtr() : _block(nullptr), _ptr(nullptr) {}
    SharedPtr(T* ptr) : _block(nullptr), _ptr(ptr) 
    {
        _block = new RefCountBlock();
        cout << "RefCount : " << block->refCount << endl;
    }

    SharedPtr(const SharedPtr<T>& other)
    :_ptr(other._ptr), _block(other._block)
    {
        if (_ptr != nullptr)
        {
            _block->refCount++;
            cout << "RefCount : " << _block->refCount << endl;
        }
    }
    
    ~SharedPtr()
    {
        if (_ptr != nullptr)
        {
            _block->refCount--;
            cout << "RefCount : " << _block->refCount << endl;

            if (_block->refCount <= 0)
            {
                delete _block;
                delete _ptr;
                _ptr = nullptr;
            }
        }
    }

    shared_ptr<T>& operator=(const SharedPtr<T>& other)
    {
        _ptr = other._ptr;
        _block = other._block;

        if (_ptr != nullptr)
        {
            _block->refCount++;
            cout << "RefCount : " << _block->refCount << endl;
        }

        return *this;
    }

    T* operator->()
    {
        if (_ptr != nullptr)
            return _ptr;

        return nullptr;
    }

private:
    T* _ptr;
    RefCountBlock* _block;
};

void PrintPlayer(shared_ptr<Player> player)
{
    player->Print();
}

void PrintPlayer(SharedPtr<Player> player)
{
    player->Print();
}

int main()
{
    string str;
    //shared_ptr<Player> player1 = shared_ptr<Player>(new Player());
    //shared_ptr<Player> player2 = make_shared<Player>(5);
    
    shared_ptr<Player> player = make_shared<Player>(5);
    shared_ptr<Player> player2 = make_shared<Player>(8);

    player->SetTarget(player2);
    player->Attack();
    player2->SetTarget(player);
    player2->Attack();
    
    // shared_ptr의 순환고리 문제 해결법
    // 1. 소멸자에서 target을 nullptr로 바꾸기
    //player->SetTarget(nullptr);
    // 2. weak_ptr 사용

    cout << "Hello World!\n";

    unique_ptr<Player> up = make_unique<Player>(5);

}