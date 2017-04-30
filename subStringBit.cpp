#include<iostream>
using namespace std;

int setsubstringbits(int N, int M, int i, int j)
{
	int mask = ~0;
	int left = mask << (j+1);
	int right = (1 << i) - 1;
	mask = left | right;
	N = (N & mask) | (M << i);
	return N;
}

int main()
{
	cout << setsubstringbits(1024,21,2,6);
	return 0;
}
