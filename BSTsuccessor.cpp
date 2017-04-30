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

int findMin(Node *root)
{
	if(root == NULL) return -1;
	Node *curr = root;

	while(curr->left != NULL) 
		curr = curr->left;

	return curr->value;
}

int findSucessor_p(Node *n)
{
	if(n->right)
		return findMin(n->right);
	else
	{
		if(n->parent->left && n->parent->left == n)
			return n->parent->value;
		else
		{
			Node *p = n->parent;
			while(p->parent && p->value < n->value)
				p = p->parent;
			return p->value > n->value ? p->value : -1;
		}
	}
	return -1;
}


int findSuccessor_r(Node *root, Node *n)
{
	if(n == NULL) return -1;
	
	if(n->right != NULL) 
		return findMin(n->right);

	Node *curr = root;
	Node *succ = NULL;
	while(curr != NULL)
	{
		if(n->value < curr->value)
		{
			succ = curr;
			curr = curr->left;
		}
		else if(n->value > curr->value)
		{
			curr = curr->right;
		}
		else
			break;
	}
	return succ->value;
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

	cout << findSuccessor_r(root, root->left->left->right->right);
	return 0;
}