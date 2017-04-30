#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<map>

using namespace std;

void permute_(string s,string curr, vector<string>& result)
{
	int length = s.length();
	
	if(!length)
	{
		result.push_back(curr);
		return;
	}
	
    for(int i = 0; i < length; ++i)
	{
		string first = curr + s.substr(i,1);
		string remainder = s.substr(0,i) + s.substr(i+1,length-i-1);
		permute_(remainder,first,result);
	}
}

void permute_dup(string curr, map<char,int> m, vector<string>& res, int n)
{
	int curr_length = curr.length();
	if (n==curr_length){
		res.push_back(curr);
		return;
	}

	for (map<char,int>::iterator i = m.begin(); i!=m.end(); i++){
		if (i->second!=0){
			char c = i->first;
			string f = curr+c;
			i->second--;
			permute_dup(f,m,res,n);
			i->second++;
		}
	}
}

int main() {
    string s = "abbc";
    vector<string> result;
    permute_("abc","", result);
	int n =  result.size();
	for (int i = 0; i < n; i++)
	{
		cout<<result[i]<<endl;
	}
	cout << endl;

    map <char, int> m;
	vector<string> res;
    n = s.length();
    for (int i = 0; i < n; i++)
    {
	  if (m.find(s[i])!=m.end())
		m.find(s[i])->second++;
	  else
		m.insert(make_pair(s[i],1));
    }
	permute_dup("",m,res,n);

	n =  res.size();
	for (int i = 0; i < n; i++)
	{
		cout<<res[i]<<endl;
	}
    return 0;
}
