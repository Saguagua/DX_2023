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
	Node* root = new Node("개발팀");
	{
		Node* children_1 = new Node("프로그래밍팀");
		root->_childeren.push_back(children_1);
		{
			Node* children_2 = new Node("클라이언트");
			children_1->_childeren.push_back(children_2);
		}
		{
			Node* children_2 = new Node("서버");
			children_1->_childeren.push_back(children_2);
		}
		{
			Node* children_2 = new Node("엔진");
			children_1->_childeren.push_back(children_2);
		}
	}
	{
	Node* children_1 = new Node("기획");
	root->_childeren.push_back(children_1);
	{
		Node* children_2 = new Node("스토리");
		children_1->_childeren.push_back(children_2);
	}
	{
		Node* children_2 = new Node("레벨디자인");
		children_1->_childeren.push_back(children_2);
	}
	{
		Node* children_2 = new Node("밸런스");
		children_1->_childeren.push_back(children_2);
	}
	}
	{
	Node* children_1 = new Node("아트");
	root->_childeren.push_back(children_1);
	{
		Node* children_2 = new Node("배경");
		children_1->_childeren.push_back(children_2);
	}
	{
		Node* children_2 = new Node("원화");
		children_1->_childeren.push_back(children_2);
	}
	{
		Node* children_2 = new Node("모델링");
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