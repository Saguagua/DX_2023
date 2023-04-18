#include <iostream>

using namespace std;

// abstraction : 추상화

//추상 클래스 : 순수가상함수가 단 하나라도 포함된 클래스
//분모의 순수가상함수가 있을 경우 그 것을 override 하지 않은 클래스

// 숨겨진 것에 접근할 때 필요한 기능

class Bank
{
public:
	virtual void PrintAccount() = 0;
};

class KakaoBank : public Bank
{
public:
	virtual void PrintAccount() override { cout << "카카오 뱅크" << endl; }
};

class ShinHanBank : public Bank
{
public:
	virtual void PrintAccount() override { cout << "신한 은행" << endl; }
};

class KBBank : public Bank
{
public:
	virtual void PrintAccount() override { cout << "KB 은행" << endl; }
};

int main()
{
	//1. 상속 받은 객체가 아무 정의도 내리지 않았을 때
	//2. 객체화 되면 안되는 클래스도 객체화 될 수 있음

	Bank* kakao = new KakaoBank();
	Bank* shinhan = new ShinHanBank();
	Bank* kb = new KBBank();

	kakao->PrintAccount();
	shinhan->PrintAccount();
	kb->PrintAccount();

	
	delete kb;
	delete shinhan;
	delete kakao;

	return 0;

}

