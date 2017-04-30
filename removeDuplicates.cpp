#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void removeDup(string &str)
{
	int length = str.length();
	if(length < 2) return;
	int newIndex = 0, curIndex= 0, k = 0;
	while(curIndex < length)
	{
		for(k = 0; k < newIndex; k++)
		{
			if(str[k] == str[curIndex] ) 
			    break;
		}
		if(k == newIndex)
		{
			str[newIndex] = str[curIndex++];
			++newIndex;
		}
		else
		    curIndex++;
	}
	str.erase(newIndex);
}

int main()
{
	string input;
	cout << "enter the strings you want to reverse..use empty line to finish" << endl;
	
	do {
         getline(std::cin,input);
	     
		 removeDup(input);
		 cout << "The string with duplicates  removed " << input << endl;

	}while(!input.empty());

	return 0;
}