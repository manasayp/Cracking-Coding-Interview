#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Node
{
public:
	int value;
	Node *left;
	Node *right;
	Node(int value)
	{
       this->value = value;
	   this->left = NULL;
	   this->right = NULL;
	}
};

vector<list<int> *> createList(Node *root)
{
	int i = -1;
	queue<Node *> q;
	vector<list<int> *> lists; /*array of linked lists*/
	list<int> *llist;
    int prevCount = 0, currCount; /* previous level node count and current level node count*/
	q.push(root);
	currCount = 1;
	while(!q.empty())
	{
		Node *x = q.front();
		q.pop();
		if(prevCount == 0) /* start of new level - create a new linked list*/
		{
			llist = new list<int>();			
			llist->push_back(x->value);
			lists.push_back(llist);	
			prevCount = currCount - 1;
			currCount = 0;
		}
		else /*push to the existing list*/
		{
			llist->push_back(x->value);
			prevCount--;
		}
		if(x->left)  /*add values to queue*/
		{
			q.push(x->left);
			currCount++;
		}
		if(x->right)
		{
			q.push(x->right);
			currCount++;
		}
	}
	return lists;
}

int main()
{
	Node *root = new Node(5);
	root->left = new Node(10);
	root->right = new Node(15);
	root->left->left = new Node(20);
	root->left->right = new Node(25);
	root->right->left = new Node(30);
	root->right->right = new Node(35);
	root->left->left->left = new Node(22);
	root->left->left->right = new Node(24);
	root->left->right->left = new Node(2);
	root->right->right->left = new Node(4);

	vector<list<int> *> lists;
	lists = createList(root);
	list<int>::iterator it;
	for(int i = 0; i < lists.size(); ++i)
	{
		for(it = lists[i]->begin(); it != lists[i]->end(); ++it)
		{
			cout << " -> " << *it ;
		}
		cout << endl << endl;
	}
	return 0;
}