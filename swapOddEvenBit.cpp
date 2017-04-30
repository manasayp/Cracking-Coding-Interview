#include<iostream>
using namespace std;

int swapOddEvenBits(int N)
{
	return ((N & 0xaaaaaaaa) >> 1) | ((N & 0x55555555) << 1);
}

int main()
{
	cout << swapOddEvenBits(58);
	return 0;
}
