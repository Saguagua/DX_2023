#include "Aggro.h"

void Aggro::Push(Player* p)
{
	if (last == 4)
	{
		if (arr[last]->GetAtk() >= p->GetAtk())
			return;

		arr[last] = p;
	}
	else if (last < 4)
	{
		arr[last] = p;
		last++;
	}

	int big;
	Player* tmp;

	for (int i = start; i < last - 1; i++)
	{
		for (int j = i + 1; j < last; j++)
		{
			if (arr[big]->GetAtk() < arr[j]->GetAtk())
				big = j;
		}
		
		tmp = arr[i];
		arr[i] = arr[big];
		arr[big] = tmp;

	}
}

Aggro::GetLast()
{
	return arr[last--];
}

void Aggro::Print()
{
}
