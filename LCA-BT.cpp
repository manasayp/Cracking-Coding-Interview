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

Node * findLca(Node *root, int n1, int n2)
{
	if(root == NULL) return NULL;
	if(root->value == n1 || root->value == n2) return root;
	
	Node *left = findLca(root->left, n1, n2);
	Node *right = findLca(root->right, n1, n2);

	if(left && right) return root;

	if(!left && !right) return NULL;

	return left ? left: right;
}

int findAncestor(Node *root, int n1, int n2)
{
	Node *result = findLca(root, n1, n2);
	return result->value;
}

/*find Depth of nodes*/
int findDepth(Node *n)
{
	int d = -1;
	while(n)
	{
		n = n->parent;
		d++;
	}
	return d;
}

/*Using Parent Pointer*/
int findAncestor_p(Node *root, Node *n1, Node *n2)
{
	int d1 = findDepth(n1);
	int d2 = findDepth(n2);
	int diff = d1 - d2; 

	if(diff > 0)
	{
		while(diff--)
			n1 = n1->parent;
	}
	else
	{
		diff = -diff;
		while(diff--)
			n2 = n2->parent;
	}
	while(n1 && n2)
	{
		if(n1 == n2)
			return n1->value;
		n1 = n1->parent;
		n2 = n2->parent;
	}
	return -1;
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

	cout << findAncestor_p(root,root->right->left->left,root->right->right->left);
	return 0;
}