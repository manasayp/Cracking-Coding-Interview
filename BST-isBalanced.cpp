#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct treeNode
{
	int value;
	struct treeNode* left, *right;
};

treeNode* makeNode(int value)
{
	treeNode *newNode;
	newNode = new treeNode;
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

int maxDepth(treeNode *root)
{
	if(root == NULL) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(treeNode *root)
{
	if(root == NULL) return 0;
	return 1 + min(minDepth(root->left), minDepth(root->right));
}

bool isBalanced(treeNode *root)
{

	if(root == NULL) return true;
	return (maxDepth(root) - minDepth(root)) <=1;
}

int main()
{
    struct treeNode *root = makeNode(20);
    root->left = makeNode(8);
    root->right = makeNode(22);
    root->left->left = makeNode(4);
    root->left->right = makeNode(12);
    root->left->right->left = makeNode(10);
    root->left->right->right = makeNode(14);
	if(isBalanced(root))
		cout << "The tree is balanced " << endl;
	else
		cout << "The tree is not balanced " << endl;
    return 0;
}