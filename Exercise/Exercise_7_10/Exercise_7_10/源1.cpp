#include<iostream>
#include<string>
using namespace std;

string chenge_place(string s)
{
	int len = s.size();
	int place_count = 0;

	string retStr;
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == ' ')
			retStr += "%23";
		else
			retStr += s[i];
	}
	return retStr;
}
int main()
{
	string s;
	while (getline(cin,s))
		cout << chenge_place(s) << endl;
	return 0;
}