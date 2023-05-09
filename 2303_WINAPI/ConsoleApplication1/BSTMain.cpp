#include <iostream>
#include "BST.h"
using namespace std;
int main()
{
	BST bst;
	bst.insert(4);
	bst.insert(2);
	bst.insert(3);
	bst.insert(6);
	bst.insert(1);
	bst.insert(5);

	Node* a1 = bst.search(bst._root, 1);
	Node* a2 = bst.search(bst._root, 2);
	Node* a3 = bst.search(bst._root, 3);
	Node* a4 = bst.search(bst._root, 4);
	Node* a5 = bst.search(bst._root, 5);
	Node* a6 = bst.search(bst._root, 6);
	Node* b = bst.Max(bst._root);
	Node* c = bst.Min(bst._root);
	Node* d1 = bst.Next(a1);
	Node* d2 = bst.Next(a2);
	Node* d3 = bst.Next(a3);
	Node* d4 = bst.Next(a4);
	Node* d5 = bst.Next(a5);
	Node* d6 = bst.Next(a6);
	Node* e1 = bst.Previous(a1);
	Node* e2 = bst.Previous(a2);
	Node* e3 = bst.Previous(a3);
	Node* e4 = bst.Previous(a4);
	Node* e5 = bst.Previous(a5);
	Node* e6 = bst.Previous(a6);

	cout << "bst.search(bst._root, 5) ->" << a1->key << endl;
	cout << "bst.Max(bst._root) ->" << b->key << endl;
	cout << "bst.Min(bst._root) ->" << c->key << endl;
	cout << "bst.Next(bst._root) ->" << d1->key << endl;
	cout << "bst.Previous(a)" << e1->key << endl;
}