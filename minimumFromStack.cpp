#include<iostream>
#include<stack>
using namespace std;

class MinStack
{
	stack<int> st;
	stack<int> minSt;
public:
	MinStack(){}
	void push(int x)
	{
		st.push(x);
		if(minSt.empty() || x <= minSt.top())
			minSt.push(x);
	}
	int pop()
	{
		if(st.empty()) throw "Invalid Operation";
		int x = st.top();
		st.pop();
		if(x == minSt.top())
		{ 
			minSt.pop();
		}
		return x;
	}
	int getMin()
	{
		if(minSt.empty())
		{
			throw "Invalid Operation";
		}
		else
			return minSt.top();
	}
	int top()
	{
		return st.top();
	}
	int size()
	{
		return st.size();
	}
};

class mstack
{
	int minimum;
	stack<int> st;
public:
	mstack()
	{
		minimum = INT_MAX;
	}
	int getMin()
	{
		if(!st.empty())
			return minimum;
		else
			throw "Invalid Exception";
	}
	void push(int x)
	{
		st.push(x);
		if(x < getMin())
			minimum = x;
	}
	int pop()
	{
		if(st.empty()) 
			throw "Invalid exception";
		int x = st.top();
		if(x == minimum)
		{
			stack<int> temp;
			int tempmin = INT_MAX;
			while(!st.empty())
			{
				int element = st.top();
				if(element < tempmin)
					tempmin = element;
				temp.push(element);
				st.pop();
			}
			while(!temp.empty())
			{
				st.push(temp.top());
				temp.pop();
			}
			minimum = tempmin;
		}
		st.pop();
		return x;
	}
};

int main()
{
	mstack s;
	s.push(5);
	s.push(1);
	s.push(15);
	s.push(9);
	s.push(4);
	s.push(7);
	s.push(12);
	cout << "Minimum is "<< s.getMin() << endl;
	cout << "Popped off " << s.pop() << endl;
	cout << "Minimum is "<< s.getMin() << endl;
	cout << "Popped off " << s.pop() << endl;
	cout << "Popped off " << s.pop() << endl;
	cout << "Popped off " << s.pop() << endl;
	cout << "Minimum is "<< s.getMin() << endl;
	cout << "Popped off " << s.pop() << endl;
	cout << "Popped off " << s.pop() << endl;
	cout << "Minimum is "<< s.getMin() << endl;
	cout << "Popped off " << s.pop() << endl;
	cout << "Minimum is "<< s.getMin() << endl;
	return 0;
}