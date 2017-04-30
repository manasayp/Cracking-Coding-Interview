#include<iostream>
#include<stack>
using namespace std;

void reverse_bit(unsigned long &x)
{
	int numbits = sizeof(x)*8;
	int half = numbits/2;
	int i = 0;
	while(i < half)
	{
		if(((x & 1 << numbits-1-i) && !(x & 1 << i)) ||  (!(x & 1 << numbits-1-i) && (x & 1 << i)))
		{
			x ^= 1 << numbits -1-i;
			x ^= 1 << i;
		}
		i++;
	}
}

int main()
{
	unsigned long x = 2147483648;
	reverse_bit(x);
	cout << x;
	return 0;
}
