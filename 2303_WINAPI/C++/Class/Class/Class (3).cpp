#include <iostream>

using namespace std;

// Class : 객체지향의 3속성

// class 와 struct 99% 동일하다.
// 접근지정자 public, private, (protected)

struct Vector2
{
	// 암시적 public
	int x;
	int y;
};

class Player
{
public:
	// Player클래스의 기본 생성자 : 선언하고 정의하지 않을 경우, 암시적 생성된다(다른 생성자가 없을 시)
	Player()
	{
		cout << "기본생성자 호출!!!" << endl;
		_hp = 0;
		_atk = 0;
		_name = "";
	}

	// Player클래스의 타입변환 생성자 : 
	Player(int hp)
	{
		cout << "타입변환 생성자 호출!!!" << endl;
		_hp = hp;
		_atk = 0;
		_name = "";
	}

	Player(int hp, int atk, string name)
	{
		cout << "타입변환 생성자 호출!!!" << endl;
		_hp = hp;
		_atk = atk;
		_name = name;
	}

	// 복사(대입)생성자 : 암시적으로 만들어준다.
	Player(const Player& other)
	{
		cout << "복사대입생성자 호출!!!" << endl;
		_hp = other._hp;
		_atk = other._atk;
		_name = other._name;
	}

	// 파괴자 : 암시적으로 무조건 생성
	~Player()
	{
		cout << "파괴자 호출!!!" << endl;
	}

	void PrintSelf()
	{
		cout << _hp << endl;
		cout << _atk << endl;
		cout << _name << endl;
	}

private:
	// 암시적 private
	int _hp; // 속성
	int _atk;
	string _name;
};

// 클래스
// 객체 : 클래스로 생성한 얘들을 객체라고 한다.
// 객체의 기능: ex) PrintSelf => 멤버 함수
// 객체의 속성: ex)hp,atk,name => 멤버 변수,, 앞에 m_ 혹은 _ 로 멤버변수인 것을 표시해준다(컨벤션)

// 객체의 생성: 생성자

int main()
{
	Player player = Player(100);
	// player.hp = 0;
	player.PrintSelf();
	// player.

	Player player2 = Player(player);
	player2.PrintSelf();

	return 0;
}