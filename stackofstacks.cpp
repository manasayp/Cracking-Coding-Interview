#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class StackOfStacks
{
	vector<stack<int>> st;
	int MAXCAPACITY;
public:
	StackOfStacks(int capacity)
	{
		MAXCAPACITY = capacity;
	}

	void push(int x)
	{
		if(st.empty())
		{
			cout << "Creating new stack " << endl;
			stack<int> newStack;
			newStack.push(x);
			st.push_back(newStack);
		}
		else
		{
			stack<int> currStack;
			currStack = st.back();
			st.pop_back();
			if(currStack.size() < MAXCAPACITY)
			{
				currStack.push(x);
				st.push_back(currStack);
			}
			else
			{
				st.push_back(currStack);
				cout << "Creating new stack " << endl;
				stack<int> newStack;
				newStack.push(x);
				st.push_back(newStack);
			}
		}
	}

	int pop()
	{
		int x;
		if(st.empty()) throw "Invalid Operation";

		stack<int> currStack = st.back();
		st.pop_back();

		x = currStack.top();
		currStack.pop();
		
		if(!currStack.empty())
			st.push_back(currStack);

		return x;
	}

	int popFrom(int StackNo)
	{
		stack<int> s = st.at(StackNo);
		if(s.empty())
			throw "Invalid Operation";
		int x = s.top();
		s.pop();
		st.at(StackNo) = s;
		return x;
	}
};

int main()
{
	StackOfStacks s(2);
	s.push(5);
	s.push(1);
	s.push(15);
	s.push(9);
	s.push(4);
	s.push(7);
	s.push(12);
	cout << "Popped off " << s.pop() << endl;
	cout << "Popped off " << s.pop() << endl;
	cout << "Pop from 2nd stack "<< s.popFrom(1) << endl;
	cout << "Popped off " << s.pop() << endl;
	s.push(28);
	cout << "Popped off " << s.pop() << endl;
	s.push(19);
	cout << "Popped off " << s.pop() << endl;
	cout << "Popped off " << s.pop() << endl;
	cout << "Popped off " << s.pop() << endl;
	s.push(51);
	s.push(11);
	s.push(13);
	cout << "Popped off " << s.pop() << endl;
	return 0;
}