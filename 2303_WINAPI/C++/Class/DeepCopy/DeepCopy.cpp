#include <iostream>

using namespace std;

class Pet
{
public :
	Pet() : _hp(100) { cout << "생성" << endl; }
private :
	int _hp;
};

class Player
{
public :
	Player()
	{
		_pet = new Pet();
	}



	~Player()
	{
		delete _pet;
	}
private :
	Pet* _pet;
};

int main()
{
	Player player = Player();
	Player player2 = Player(player);



	return 0;
}