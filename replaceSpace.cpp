#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void replaceSpace(string &str)
{
	int length = str.length() , count = 0, newLength;
	for(int i = 0; i < length; i++)
	{
		if(str[i] == ' ') count++;
	}
	newLength = length + 2 * count;
	str.resize(newLength);
	for(int i = length - 1; i >= 0; i--)
	{
		if(str[i] ==  ' ')
		{
			str[--newLength] = '0';
			str[--newLength] = '2';
			str[--newLength] = '%';
		}
		else
		{
			str[--newLength] = str[i];
		}
	}
}

int main()
{
	string input1;
	cout << "enter the strings..use empty line to finish" << endl;
	
	do {
         getline(std::cin,input1);
	     
		 replaceSpace(input1);
		 cout << "The strings is " << input1 << endl;

	}while(!input1.empty());

	return 0;
}