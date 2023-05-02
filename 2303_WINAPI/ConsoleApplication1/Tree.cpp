#include "Tree.h"
#include "iostream"
#include "string"
#include "vector"

using namespace std;

struct Node
{
	Node() {}
	Node(const string data) : _data(data) {}
	vector<Node*> _childeren;
	string _data;
};

Node* CreateTree()
{
	Node* root = new Node("������");
	{
		Node* children_1 = new Node("���α׷�����");
		root->_childeren.push_back(children_1);
		{
			Node* children_2 = new Node("Ŭ���̾�Ʈ");
			children_1->_childeren.push_back(children_2);
		}
		{
			Node* children_2 = new Node("����");
			children_1->_childeren.push_back(children_2);
		}
		{
			Node* children_2 = new Node("����");
			children_1->_childeren.push_back(children_2);
		}
	}
	{
	Node* children_1 = new Node("��ȹ");
	root->_childeren.push_back(children_1);
	{
		Node* children_2 = new Node("���丮");
		children_1->_childeren.push_back(children_2);
	}
	{
		Node* children_2 = new Node("����������");
		children_1->_childeren.push_back(children_2);
	}
	{
		Node* children_2 = new Node("�뷱��");
		children_1->_childeren.push_back(children_2);
	}
	}
	{
	Node* children_1 = new Node("��Ʈ");
	root->_childeren.push_back(children_1);
	{
		Node* children_2 = new Node("���");
		children_1->_childeren.push_back(children_2);
	}
	{
		Node* children_2 = new Node("��ȭ");
		children_1->_childeren.push_back(children_2);
	}
	{
		Node* children_2 = new Node("�𵨸�");
		children_1->_childeren.push_back(children_2);
	}
	}
	return root;
}

void PrintTree(Node* root, int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "-";
	}

	cout << root->_data << endl;

	for (auto node : root->_childeren)
	{
		PrintTree(node, depth+1);
	}
}

int main()
{
	Node* root = CreateTree();
	PrintTree(root, 0);
}