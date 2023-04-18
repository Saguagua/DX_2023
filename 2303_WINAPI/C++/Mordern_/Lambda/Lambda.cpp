#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;


class Player
{
public:
	Player(int hp, int atk) :_hp(hp), _atk(atk) {}
	~Player() {}
	const int& GetHp() const { return _hp; }
	const int& GetAtk() const { return _atk; }

private:
	int _hp;
	int _atk;

};

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	#pragma region Lambda
	vector<int> v;

	v.push_back(1);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	v.push_back(6);

	//int compareNum = 5;
	//int* comptr = &compareNum;
	//int a = 2;
	//auto iter = std::find_if(v.begin(), v.end(), [compareNum, a](int element)-> bool{
	//	return element > compareNum;
	//});

	////std::sort(v.begin(), v.end(), greater<int>());
	//std::sort(v.begin(), v.end(), [](const int a, const int b)
	//	-> bool
	//	{
	//		return a > b;
	//	}
	//
	//);
	////cout << *iter << endl;
	#pragma endregion

	vector<Player*> players;

	players.reserve(1000);

	for (int i = 0; i < 1000; i++)
	{
		Player* player = new Player(rand() % 50, rand() % 20);
		players.push_back(player);
	}

	std::sort(players.begin(), players.end(), [](const Player* const element1, const Player* const element2)->
		bool
		{
			if (element1->GetHp() == element2->GetHp())
				return element1->GetAtk() > element2->GetAtk();
			return element1->GetHp() > element2->GetHp();
		}
	);

	return 0;
}
