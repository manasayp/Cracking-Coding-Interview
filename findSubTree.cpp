#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;

class Node
{
public:
	int value;
	Node *left;
	Node *right;
	Node *parent;
	Node(int value)
	{
       this->value = value;
	   this->left = NULL;
	   this->right = NULL;
	   this->parent  = NULL;
	}
};

bool matchTree(Node *n1, Node *n2)
{
	if(n1 == NULL && n2 == NULL)
		return true;
	if(n1 == NULL || n2 == NULL)
		return false;
	if(n1->value != n2->value)
		return false;
	return matchTree(n1->left, n2->left) && matchTree(n1->right, n2->right);
}

bool subTree(Node *n1, Node *n2)
{
	if(n1 == NULL)
		return false;
	if(n1->value ==  n2->value)
		return matchTree(n1, n2);
	return (subTree(n1->left, n2)  || subTree(n1->right, n2));
}

bool check4subtree(Node *n1, Node *n2)
{
	if(subTree == NULL) return true;
	else return subTree(n1, n2);
}

int main()
{
	Node *root = new Node(25);
	root->left = new Node(20);
	root->right = new Node(36);
	root->left->left = new Node(10);
	root->left->right = new Node(22);
	root->right->left = new Node(30);
	root->right->right = new Node(40);
	root->left->left->left = new Node(5);
	root->left->left->right = new Node(12);
	root->left->left->left->left = new Node(1);
	root->left->left->left->right = new Node(8);
	root->left->left->right->right = new Node(15);
	root->right->left->left  = new Node(28);
	root->right->right->left = new Node(38);
	root->right->right->right = new Node(48);
	root->right->right->right->left = new Node(45);
	root->right->right->right->right = new Node(50);

	root->parent = NULL;
	root->left->parent = root;
	root->right->parent = root;
	root->left->left->parent = root->left;
	root->left->right->parent = root->left;
	root->left->left->left->parent = root->left->left;
	root->left->left->right->parent = root->left->left;
	root->left->left->right->right->parent = root->left->left->right;
	root->left->left->left->left->parent = root->left->left->left;
	root->left->left->left->right->parent = root->left->left->left;
	root->right->left->parent = root->right;
	root->right->right->parent = root->right;
	root->right->left->left->parent = root->right->left;
	root->right->right->left->parent = root->right->right;
	root->right->right->right->parent = root->right->right;
	root->right->right->right->left->parent = root->right->right->right;
	root->right->right->right->right->parent = root->right->right->right;

	/*Sub Tree*/
	Node *root1 = new Node(48);
	root1->left = new Node(45);
	root1->right = new Node(50);
	
	if(check4subtree(root,root1))
		cout << "Sub Tree is present in main tree" << endl;
	else
		cout << " Sub Tree is not found" << endl;
	return 0;
}