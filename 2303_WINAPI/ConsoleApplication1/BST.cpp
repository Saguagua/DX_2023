#include "BST.h"
#include <iostream>

using namespace std;

BST::BST()
{
}

BST::~BST()
{
}

void BST::insert(int value)
{
	if (_root == nullptr)
	{
		_root = new Node(value);
		return;
	}
	Node* current = _root;
	Node* node = new Node(value);

	while (true)
	{
		if (current == nullptr)
			break;

		node->parent = current;

		if (current->key < node->key)
			current = current->right;
		else
			current = current->left;
	}

	current = node;
	
	if (current->parent->key < current->key)
		current->parent->right = current;
	else
		current->parent->left = current;
}

Node* BST::search(Node* node, int key)
{
	if (node == nullptr)
		return nullptr;

	while (true)
	{
		if (node == nullptr)
		{
			cout << "찾는 노드가 없습니다 " << endl;
			return nullptr;
		}

		if (node->key == key)
			return node;
		else if (node->key < key)
			node = node->right;
		else
			node = node->left;
	}

	return nullptr;
}

Node* BST::Min(Node* node)
{
	if (node == nullptr)
		return nullptr;

	while (true)
	{
		if (node->left == nullptr)
			break;
		node = node->left;
	}

	return node;
}

Node* BST::Max(Node* node)
{
	if (node == nullptr)
		return nullptr;

	while (true)
	{
		if (node->right == nullptr)
			break;
		node = node->right;
	}

	return node;
}

Node* BST::Previous(Node* node)
{
	if (node == nullptr)
		return nullptr;

	Node* current = node;

	if (current->left == nullptr)
	{
		while (true)
		{
			current = current->parent;
			if (current == nullptr)
				return nullptr;
			if (current->key < node->key)
				return current;
		}
	}
	
	current = current->left;

	while (true)
	{
		if (current->right == nullptr)
			break;
		current = current->right;
	}

	return current;
}

Node* BST::Next(Node* node)
{
	if (node == nullptr)
		return nullptr;

	Node* current = node;

	if (current->right == nullptr)
	{
		while (true)
		{
			current = current->parent;
			if (current == nullptr)
				return nullptr;
			if (current->key > node->key)
				return current;
		}
	}
	
	current = current->right;

	while (true)
	{
		if (current->left == nullptr)
			break;
		current = current->left;
	}

	return current;
}
