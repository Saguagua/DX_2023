#pragma once
#include <iostream>

template <typename T>
struct Node
{
	Node() : data(T()), prev(nullptr), next(nullptr) {}
	Node(const T& newData) : data(newData), prev(nullptr), next(nullptr) {}

	T data;
	Node<T>* next;
	Node<T>* prev;
};
/*
//환형 연결 리스트
template<class T>
class ListClass
{
public:
	ListClass()
		:_head(nullptr), _size(0)
	{
		_head = new Node<T>();
		_head->next = _head;
		_head->prev = _head;
	}

	~ListClass()
	{
		clear();
		delete _head;
	}

	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);

		Node* prev = before;
		Node* next = before->next;

		newNode->prev = prev;
		newNode->next = next;

		prev->next = newNode;
		next->prev = newNode;

		_size++;

		return newNode;
	}

	void push_back(const int& value)
	{
		AddNode(_head->prev, value);
		return;
	}

	void pop_back()
	{
		RemoveNode(_head->prev);
		return;
	}

	void push_front(const int& value)
	{
		AddNode(_head, value);
	}

	void pop_front()
	{
		RemoveNode(_head->next);
		return;
	}

	Node* RemoveNode(Node* node)
	{
		Node* prev = node->prev;
		Node* next = node->next;

		prev->next = next;
		next->prev = prev;

		delete node;

		_size--;

		return next;
	}

	const int& operator[](const unsigned int& index)
	{
		if (index >= _size)
			return INT_MAX;
	}

	void clear()
	{
		Node* start = _head->next;
		while (true)
		{
			if (start == _head) break;

			start = RemoveNode(start);
		}

		_size = 0;
	}

	unsigned int size() { return _size; }

private:
	Node<T>* _head;
	unsigned int _size;
};
*/