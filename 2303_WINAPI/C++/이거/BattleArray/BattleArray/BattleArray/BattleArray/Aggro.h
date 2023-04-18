#pragma once
#include "framework.h"

class Aggro
{
public:
    Aggro() {}

    ~Aggro() {}

    void Push(Player* p);
    Player* GetLast();
    void Print();


private:
    Player* arr[5] = { 0 };
    int start = 0;
    int last = 0;

};