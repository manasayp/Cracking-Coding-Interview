#include<iostream>
#include<vector>
using namespace std;

typedef struct treeNode
{
	int value;
	struct treeNode *left;
	struct treeNode *right;
}Node;

void Inorder(Node *root)
{
	if(root == NULL) return;
	Inorder(root->left);
	cout << root->value <<endl;
	Inorder(root->right);
}

Node * createBTreeUtil(vector<int> a, int l, int r)
{
	if(r < l) return NULL;

	int mid = (l + r)/ 2;
	Node *root = new Node();
	root->value = a[mid];
	root->left = createBTreeUtil(a, l, mid-1);
	root->right = createBTreeUtil(a, mid+1, r);
	return root;
}

Node * createBTree(vector<int> a)
{
	if(a.size() == 0) return NULL;
	return createBTreeUtil(a,0,a.size()-1);
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,12};
	vector<int> a;
	Node *root;
	a.reserve(10);
	a.insert(a.begin(),arr,arr+sizeof(arr)/sizeof(int));
	root = createBTree(a);
	Inorder(root);
	return 0;
}