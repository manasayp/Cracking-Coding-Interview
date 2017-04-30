#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<map>

using namespace std;

enum type
{
	quarter = 25,
	dime = 10,
	nickel = 5,
	pennies = 1
};

int CountWays(type current, int money)
{
	int count = 0, value;
	if(money < 0) return 0;
	if(money == 0) return 1;

	count += CountWays(pennies, money - (int)current);
	count += CountWays(nickel, money - (int)current);
	count += CountWays(dime, money - (int)current);
	count += CountWays(quarter, money - (int)current);
	return count;
}


int main()
{
	cout << CountWays(pennies,25);
	return 0;
}