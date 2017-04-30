#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isRotation(string str1, string str2)
{
	if(str1.length() != str2.length() || str1.length() <= 0 || str2.length() <= 0) return false;
	string temp = str1+str1;
	return temp.find(str2) == std::string::npos ? false : true;
}

int main()
{
	string input1,input2;
	cout << "enter the strings you want to check in different lines..euse empty line to finish" << endl;
	
	do {
         getline(std::cin,input1);
	     getline(std::cin,input2);

		 if(isRotation(input1,input2))
			cout << "The string is rotations of each other " << endl;
		 else
			 cout << "Not a rotated string" <<endl;

	}while(!input1.empty() && !input2.empty());

	return 0;
}