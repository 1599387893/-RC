#include<iostream>
#include<string>
#include<string.h>
using namespace std;
 
int main()
{
	string s1 = "aAbBcCdD";
	string s2 = "AaBbCcDd";
	if (stricmp(s1.c_str(), s2.c_str()) == 0)
		cout << "Same One" << endl;
	else
		cout << "Not Same one" << endl;
	system("pause");
	return 0;
}