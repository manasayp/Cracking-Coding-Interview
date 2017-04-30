#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*subsets can be represnted as binary numbers*/
vector<vector<char>> printSubsets(vector<char> set)
{
	int n = set.size();
	vector<vector<char>> result;
	// Run a loop for printing all 2^n
	// subsets one by obe
	for (int i = 0; i < (1<<n); i++)
	{
		vector<char> subset;
		for (int j = 0; j < n; j++)
			if ((i & (1 << j)) > 0) /*if jth bit is set, append jth char to the current subset*/
				subset.push_back(set[j]);
		result.push_back(subset); /*push the current subset to the result*/
	}
	return result;
}

int main() {
   char a[] = {'a','b','c','d'};
   vector<char> set;
   set.reserve(sizeof(a)/sizeof(char));
   set.insert(set.begin(),a,a+sizeof(a)/sizeof(char));
   vector<vector<char>> result;
   result = printSubsets(set);
   int n = result.size();
   for(int i = 0; i < n; ++i)
   {
	   vector<char> subset = result[i];
	   int l = subset.size();
	   cout << "{ ";
	   for(int j = 0; j < l; ++j)
	   {
		   cout << subset[j] << " ";
	   }
	   cout << "}" <<endl;
   }
   return 0;
}
