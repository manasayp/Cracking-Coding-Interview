#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class sstack
{
	stack<int> *st;
public:
	sstack(){st = new stack<int>();}
	
	~sstack() { delete st;}
	void push(int x)
	{
		st->push(x);
	}
	int top()
	{
		if(st->empty()) 
			throw "Invalid exception";
		int x = st->top();
		return x;
	}
	void pop()
	{
		if(st->empty()) 
			throw "Invalid exception";
		st->pop();
	}
	void sort()
	{
		stack<int> temp;
		while(!st->empty())
		{
			int x = st->top();
			st->pop();
			while(!temp.empty() && temp.top() > x)
			{ 
				st->push(temp.top());
				temp.pop();
			}
			temp.push(x);
		}
		while(!st->empty())
		{
			st->pop();
		}
		while(!temp.empty())
		{
			st->push(temp.top());
			temp.pop();
		}
	}
	bool empty()
	{
		if(size() == 0)
			return true;
		else 
			return false;
	}
	int size()
	{
		return st->size();
	}
};

int main()
{
	sstack s;
	s.push(5);
	s.push(1);
	s.push(15);
	s.push(9);
	s.push(4);
	s.push(7);
	s.push(12);
	cout << "sorted stack" << endl;
	s.sort();
	while(!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}