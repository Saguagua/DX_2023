#include <iostream>
#include <algorithm>

using namespace std;

void Shuffle(int arr[], int size, int count);
void Swap(int& a, int& b);
void SortArray(int arr[], int size);

int main()
{
	srand(unsigned int(time(nullptr)));
	int lotto[45];

	for (int i = 0; i < 45; i++)
	{
		lotto[i] = i + 1;
	}

	Shuffle(lotto, 45, 1000);
	sort(lotto, lotto + 7);

	return 0;
}

void Shuffle(int arr[], int size, int count)
{
	int randIndex_1;
	int randIndex_2;
	for (int i = 0; i < count; i++)
	{
		randIndex_1 = rand() % size;
		randIndex_2 = rand() % size;
	}
	Swap(arr[randIndex_1], arr[randIndex_2]);
}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void PrintLotto(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

//선택 정렬(Select Sort)
//[5][4][3][2][1] 중 bestIndex를 찾는다.
void SelectSort(int arr[], int size)
{
	int bestIndex = 0;
	for (int i = 0; i < size; i++)
	{
		bestIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[bestIndex] > arr[j])
			{
				bestIndex = j;
			}
		}

		Swap(arr[i], arr[bestIndex]);
	}
}

//순차 정렬(Squence Sort)
//0번째부터 n-1까지
void SortArray(int arr[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				Swap(arr[i], arr[j]);
			}
		}
	}
}

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; i++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j+1]);
			}
		}
	}
}
