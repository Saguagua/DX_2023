#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

class Pet
{
public:
	Pet() {}
	Pet(int hp, int atk) : _hp(hp) {}
private:
	friend class Player;
	int _hp = 0;
};

class Player
{
public:
	virtual void PrintInfo() abstract;
	void PrintPet(Pet* pet)
	{
		cout << pet->_hp << endl;
	}
private:
};

class Knight : public Player
{
public:
	virtual void PrintInfo() final override {}
};

class Warrior : public Knight
{
	public:
	//virtual void PrintInfo() override{} 불가능
};

using UINT = unsigned int;
typedef void(*FNDef)(void);
using FN = void(*)(void);


template<typename T>
class Vector2
{
public:
	T x;
	T y;
};

using Vector2Int = Vector2<int>;
typedef Vector2<int> Vector2Int2;

enum class Enum_State
{
	NONE,
	STUN,
	SLEEP
};

enum Animation_State
{
	NONE,
	RUN,
	SLEEP
};

int main()
{
	Enum_State state = Enum_State::NONE;

	Pet pet = Pet(50, 50);
	int tmpInt = {5};

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	auto iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}

	for (int val : v)
		cout << val << endl;

	unordered_map<int, int> map;
	map[1] = 5;
	map[2] = 7;
	map[3] = 9;

	for (pair<const int, int>& myPair : map)
	{
		cout << myPair.first << endl;
		cout << myPair.second << endl;
	}

	return 0;
}