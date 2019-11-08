#include<iostream>
#include<string>
using namespace std;

void Erase1(string& s1, string& s2)
{
	for (size_t i = 0; i < s2.size(); ++i)
	{
		while (s1.find(s2[i]) != string::npos)
			s1.erase(s1.begin() + i);
	}
}
string Erase(string& s1, string&s2)
{
	string ret;
	for (int i = 0; i < s1.size(); ++i)
	{
		if (s2.find(s1[i]) == string::npos)
			ret += s1[i];
	}
	return ret;
}
int main()
{
	string s1;
	string s2;
	while (getline(cin,s1))
	{
		getline(cin, s2);
		if (s2.empty())
			cout << s1 << endl;
		else
		{
			cout << Erase(s1, s2) << endl;
		}
	}
	system("pause");
	return 0;
}