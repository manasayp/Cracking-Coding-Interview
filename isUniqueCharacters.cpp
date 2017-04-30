#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*using sort*/
bool isUnique_sort(string str)
{
	if(str.length() == 0) return true;
	std::sort(str.begin(),str.end());
	for(int i = 1; i < str.length(); i++)
		if(str[i] == str[i-1])  return false;
	return true;
}
/* only alphabets a-z/A-Z*/
bool isUnique_hash(string str)
{
	char letters[52] = {0};
	if(str.length() == 0 ) return true;
	for(int i = 0; i < str.length(); i++){
		if(isupper(str[i]) && ( ++letters[str[i] - 'A' + 26] > 1 )) return false;
		else 
			if (++letters[str[i] - 'a'] > 1) return false;
	}
	return true;
}

/*Using bit string only a- z*/
bool isUnique_bit(string str)
{
	int letter = 0;
	if(str.length() == 0 ) return true;
	for(int i = 0; i < str.length(); i++){
	    int shift = str[i] - 'a';
		if((letter & (1 << shift))  > 0 ) return false;
		letter |= (1 << shift);
	}
	return true;
}

int main()
{
	string input;
	cout << "enter the strings you want to check..use empty line to finish" << endl;
	
	do {
         getline(std::cin,input);
	     
		 if(isUnique_hash(input))
		     cout << "The string has unique characters" << endl;
	     else
		     cout << "The string has repeated characters" << endl;

	}while(!input.empty());

	return 0;
}