
#include <iostream>

using namespace std;

int main()
{
	int randNum;
	int playerInput;
	int countInt = 0;

	srand(unsigned int(time(nullptr)));
	randNum = rand() % 500 + 1;
	cout << "컴퓨터 수 : " << randNum << endl;
	

	while (true) {
		cout << "숫자 입력" << endl;
		cin >> playerInput;

		if (randNum < playerInput)
			cout << "입력하신 숫자가 더 높습니다." << endl;
		else if (randNum > playerInput)
			cout << "입력하신 숫자가 더 낮습니다." << endl;
		else {
			cout << "정답입니다." << endl;
			break;
		}

		countInt++;
		if (countInt == 20) {
			cout << "20번을 초과했습니다." << endl;
			break;
		}
	}
}
