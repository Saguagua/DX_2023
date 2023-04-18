#include <iostream>

using namespace std;

//Class : 객체지향 3속성을 지닌다.
//구조체와 클래스는 거의 동일
//구조체는 public이 생략되어있음
//접근지정자 public, private, protected

//클래스 
//객체 : 클래스로 생성한 애들을 객체라 한다.
//객체의 기능: 맴버 함수
//객체의 속성: 맴버 변수 (보통 앞에 _붙인다)

//객체의 생성 : 생성자

struct Player_Struct
{
	Player_Struct()
	{

	}
	string name;
	int hp;
	int atk;
};

class Player_Class
{
public:
	//Player클래스의 기본 생성자 선언하고 정의하지 않으면 암시적으로 생성
    Player_Class() 
    {
    	cout << "기본 생성자 호출" << endl;
    	_hp = 0;
    	_atk = 0;
    	_name = "hun";
    }

	Player_Class(int hp, int atk, string name) //타입변환 생성자
	{
		cout << "타입변환 생성자" << endl;
		_hp = hp;
		_atk = atk;
		_name = name;
	}

	Player_Class(int hp) //타입변환 생성자
	{
		cout << "타입변환 생성자" << endl;
		_hp = hp;
		_atk = 0;
		_name = "";
	}

	//복사 생성자
	Player_Class(const Player_Class& other)
	{
		_hp = other._hp;
		_atk = other._atk;
		_name = other._name;
	}

	// 파괴자 : 암시적으로 무조건 생성, 매개변수가 필요없으므로 기본형이 끝임
	~Player_Class()
	{
		cout << "파괴자 호출" << endl;
	}

	void PrintSelf() {
		cout << _hp << endl;
		cout << _atk << endl;
		cout << _name << endl;
	}

private:
	string _name;
	int _hp;
	int _atk;
};

int main()
{
	Player_Struct player_s;
	player_s.hp = 0;
	player_s.atk = 0;
	player_s.name = "Hun";

	Player_Class player_c = Player_Class(100, 5, "huuun");
	Player_Class player = 100;
	player_c.PrintSelf();

	Player_Class player2 = Player_Class(player);
}