#include <iostream>
#include <algorithm>
#include "Lotto.h"

using namespace std;

Lotto::Lotto():_lottoNum(7)
{
	for (int i = 0; i < 45; i++)
	{
		_arr[i] = i + 1;
	}
}

Lotto::~Lotto()
{
}

void Lotto::Shuffle(int count = 1000)
{
	int randIndex1 = rand() % LOTTO;
	int randIndex2 = rand() % LOTTO;

	swap(_arr[randIndex1], _arr[randIndex2]);

}

void Lotto::Set()
{
	Lotto::Shuffle();
}



void Lotto::PrintLotto()
{
}
