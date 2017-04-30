#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isAnagram_sort(string s1,string s2)
{
	if(s1.length() != s2.length()) return false;
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	return ( s1 == s2 ) ? true : false;
}

bool isAnagram_hash(string s1,string s2)
{
	if(s1.length() != s2.length()) return false;
	int letters[256] = {0};
	int length = s1.length();
	for(int i = 0; i < length; i++)
	{
		letters[s1[i] - 'a']++;
		letters[s2[i] - 'a']--;
	}
	for(int i = 0;  i < 256; i++)
	{
		if(letters[i])
			return false;
	}
	return true;
}

int main()
{
	string input1,input2;
	cout << "enter the strings.........use empty line to finish" << endl;
	
	do {
         getline(std::cin,input1);
		 getline(std::cin,input2);
	     
		 if(isAnagram_hash(input1,input2))
			cout << "The strings are anagram" << endl;
		 else
			 cout << "The strings are not anagram" <<endl;
		 if(isAnagram_sort(input1,input2))
			cout << "The strings are anagram" << endl;
		 else
			 cout << "The strings are not anagram" <<endl;

	}while(!input1.empty() && !input2.empty());

	return 0;
}