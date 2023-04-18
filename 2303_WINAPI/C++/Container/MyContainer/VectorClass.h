#pragma once
template <typename T>
class VectorClass
{
public:

	class Iterator
	{
	public:
		Iterator() : _ptr(nullptr) {}
		Iterator(T* ptr) : _ptr(ptr) {}
		~Iterator() {}

		Iterator& operator++()
		{
			++ptr;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator tmp = *this;
			++ptr;

			return tmp;
		}

		T& operator*()
		{
			return *ptr;
		}

		bool operator==(const Iterator& other)
		{
			return ptr == other.ptr;
		}

		bool operator!=(const Iterator& other)
		{
			return ptr != other.ptr;
		}

		VectorClass<T>::Iterator begin() { return Iterator(_data); }

		VectorClass<T>::Iterator end() { return Iterator(_data + _size;) }

	private:
		T* ptr;
	};

	VectorClass() : _size(0), _capacity(0), _data(nullptr) {}
	~VectorClass()
	{

	}

	void reserve(unsigned int capacity)
	{
		_capacity = capacity;

		int* newData = new int[_capacity];

		//데이터 복사
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		if (_data != nullptr)
		{
			delete _data;
		}

		_data = newData;
	}

	void push_back(const int& value)
	{
		
	}

	void pop_back()
	{

	}

	const int& operator[](unsigned int index)
	{
		return 0;
	}
	
	const unsigned int& size() { return _size; }
	const unsigned int& capacity() { return _capacity; }

private:

	int* _data;
	unsigned int _size;
	unsigned int _capacity;
};