#include <iostream>

using namespace std;

//Functor : 함수객체
//객체 : 자료형과 생성자로 만들어진 것


//함수 객체와 포인터

//포인터 : 어떤 함수를 담아놓을 수 있다.
//함수 객체 : 자신만의 속성을 가질 수 있다.

struct ItemInfo
{
	ItemInfo() :_itemKey(0), _itemPrice(0), _itemValue(0) {}
	ItemInfo(int key, int price, int value) : _itemKey(key), _itemPrice(price), _itemValue(value) {}

	void SetItemInfo(int key, int price, int value)
	{
		_itemKey = key;
		_itemPrice = price;
		_itemValue = value;
	}

	void PrintInfo() const
	{
		cout << "key : " << this->_itemKey << endl;
		cout << "price : " << this->_itemPrice << endl;
		cout << "value : " << this->_itemValue << endl;
	}

	int _itemKey;
	int _itemPrice;
	int _itemValue;
};

//함수 포인터
typedef bool(*ItemF_byInt)(const ItemInfo&);
typedef bool(*ItemFinder)(const ItemInfo&, int, int, int);

bool FindItemByKey(const ItemInfo& item)
{
	if (item._itemKey == 5)
		return true;
	return false;
}

bool FindItemByK_P(const ItemInfo& item, int key, int price, int value)
{
	if (item._itemKey == key || key == 0)
		if (item._itemPrice == price || price == 0)
			if (item._itemValue == value || value == 0)
				return true;
	return false;
}

ItemInfo* FindItem(ItemInfo items[], int size, ItemF_byInt fn)
{
	for (int i = 0; i < size; i++)
	{
		if (fn(items[i]))
			return &items[i];
	}

	return nullptr;
}

ItemInfo* FindItem_all(ItemInfo items[], int size, ItemFinder fn, int key = 0, int price = 0, int value = 0)
{
	for (int i = 0; i < size; i++)
	{
		if (fn(items[i], key, price, value))
			return &items[i];
	}

	return nullptr;
}


#pragma region 함수객체 사용


//함수 객체
struct FinderByKey
{
public:
	bool operator()(const ItemInfo& info)
	{
		if (info._itemKey == _itemKey)
			return true;

		return false;
	}

	int _itemKey;
};

struct FinderBy_Key_Price
{
	bool operator() (const ItemInfo& info)
	{
		if (info._itemKey == _itemKey && info._itemPrice == _itemPrice)
			return true;
		return false;
	}

	int _itemKey;
	int _itemPrice;
};

struct FinderBy_Key_Price_Value
{
	bool operator() (const ItemInfo& info)
	{
		if (info._itemKey == _itemKey && info._itemPrice == _itemPrice)
			if (info._itemValue == _itemValue)
				return true;
		return false;
	}

	int _itemKey;
	int _itemPrice;
	int _itemValue;
};

template <class T>
ItemInfo* FindItem(ItemInfo items[], int size, T fn)
{
	for (int i = 0; i < size; i++)
	{
		if (fn(items[i]))
			return &items[i];
	}

	return nullptr;
}
#pragma endregion


class Functor
{
public:
	void operator()()
	{
		cout << _hello << endl;
		cout << "Hello Functor!" << endl;
	}
private:
	int _hello = 5;
};
 

int main()
{
	Functor fn;
	fn();

	ItemInfo items[10];

	for (int i = 0; i < 10; i++)
	{
		items[i].SetItemInfo(i, i * 1000, (9 - i));
	}

	FindItem(items, 10, &FindItemByKey)->PrintInfo();

	//FindItem_all (items, 10, &FindItem_all);
	FinderByKey finder;
	finder._itemKey = 5;

	FindItem(items, 10, finder)->PrintInfo();

	FinderBy_Key_Price finder_k_p;
	finder_k_p._itemKey = 4;
	finder_k_p._itemPrice = 4000;

	cout << endl;
	//key가 4, price가 4000인 아이템
	FindItem(items, 10, finder_k_p)->PrintInfo();

	// key가 8, price 8000, value 1인 아이템 찾기
	cout << endl;
	FinderBy_Key_Price_Value finder_k_p_v;
	finder_k_p_v._itemKey = 8;
	finder_k_p_v._itemPrice = 8000;
	finder_k_p_v._itemValue = 1;
	FindItem(items, 10, finder_k_p_v)->PrintInfo();
}