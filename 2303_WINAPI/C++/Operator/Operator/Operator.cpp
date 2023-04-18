#include <iostream>

using namespace std;

int main() {
    int e = 1;
    int aInt = 10;
    int bInt = 3;
    float b = 10.0f;
    float c = 2.0f;


    struct ab {
        short b;
        int ab;
    };
    
    ab x;
    short s = 1;

    cout << sizeof(x) << endl;

    bool check1 = (aInt == bInt);                     //f
    bool check2 = (aInt < bInt);                      //0
    bool check3 = (aInt != (aInt++));                 //f

    bool check4 = check1 || check2;                   //0
    bool check5 = !(check1 && check3);                //t
    bool check6 = (check1 < check3) || !check2;       //t

    //cout << check1 << check2 << check3 << check4 << check5 << check6;
    
    unsigned char stun = (1 << 1);
    unsigned char sleep = (1 << 2);
    unsigned char airborne = (1 << 3);
    unsigned char silence = (1 << 4);
    unsigned char bitflag = silence;

    if (bitflag & (stun | airborne)) {
        cout << "스턴이거나 슬립";
    }
    else {
        cout << "둘 다 아님";
    }
    return 0;
}