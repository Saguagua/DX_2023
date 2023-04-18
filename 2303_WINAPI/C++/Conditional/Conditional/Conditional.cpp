#include <iostream>

using namespace std;

void PrintStars(int inputInt);
void MultiplicationTableAll();
void MultiplicationTable(int inputInt);

int main()
{
    int playerInput;
    
    MultiplicationTableAll();

    cout << endl;

    cout << "원하는 단을 입력 : ";
    cin >> playerInput;

    MultiplicationTable(playerInput);

    cout << endl << endl;
    
    cout << "원하는 층 수 입력 : ";
    cin >> playerInput;

    PrintStars(playerInput);

}

void PrintStars(int input){
    for (int i = 1; i <= input; i++) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void MultiplicationTableAll(){
    for (int i = 1; i < 10; i++) {
        cout << i << "단 :";
        for (int j = 1; j < 10; j++) {
            cout << i * j << " ";
        }
        cout << endl;
    }
}

void MultiplicationTable(int numInt){
    cout << numInt << "단 :";
    for (int i = 1; i < 10; i++) {
        cout << numInt * i << " ";
    }
}
