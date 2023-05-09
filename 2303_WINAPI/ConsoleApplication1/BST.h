#pragma once
struct Node
{
	Node(int key)
		:key(key)
	{
	}
	int key;
	int data = 0;

	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
};

class BST
{
public:
	BST();
	~BST();

	void insert(int value);
	Node* search(Node* start, int key);
	Node* Min(Node* node);
	Node* Max(Node* node);

	Node* Previous(Node* node);
	Node* Next(Node* node);

	Node* _root;
};

