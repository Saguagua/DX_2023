#pragma once
#define LOTTO 45

class Lotto
{
public :
	Lotto();
	~Lotto();
	void Shuffle(int count = 1000);
	void Set();
	void PrintLotto();
private:
	int _arr[LOTTO];
	int _lottoNum;
};

