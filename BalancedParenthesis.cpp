#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<map>

using namespace std;

void print_(char *s, int open, int close, int count)
{
	if(open < 0 || close < open) return;
	if(open == 0 && close == 0)
	{
		for(int i = 0; i < count; ++i)
		cout << s[i];
		cout << endl;
	}
	else
	{
		if(open > 0 )
		{
			s[count] = '{';
			print_(s,open-1,close, count+1);
		}
		if(close > open)
		{
			s[count] = '}';
			print_(s,open,close-1, count+1);
		}
	}
}

void printParenthesis(int n)
{
	char *s = new char[2*n]();
	return print_(s,n,n,0);
	delete[] s;
}

int main() {
	printParenthesis(8);
    return 0;
}
