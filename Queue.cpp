#include<iostream>
#include<stack>
#include<vector>
using namespace std;

template <class T> class Queue
{
	stack<T> *st1, *st2;
public:
	Queue()
	{
		st1 = new stack<T>();
		st2 = new stack<T>();
	}

	~Queue()
	{
		delete st1;
		delete st2;
	}
	void insert(T x)
	{
		st1->push(x);
	}

	T pop()
	{
		T x;
		if(!st2->empty())
		{
			x = st2->top();
			st2->pop();
		}
		else
		{
			while(!st1->empty())
			{
				st2->push(st1->top());
				st1->pop();
			}
			x = st2->top();
			st2->pop();
		}
		return x;
	}

	int size()
	{ 
		return st1->size()+st2->size();
	}

};

int main()
{
	Queue<int> q;
	q.insert(5);
	q.insert(1);
	q.insert(15);
	q.insert(9);
	q.insert(4);
	q.insert(7);
	q.insert(12);
	cout << "Deleted off " << q.pop() << endl;
	cout << "Deleted off " << q.pop() << endl;
	cout << "Popped off " << q.pop() << endl;
	q.insert(28);
	return 0;
}