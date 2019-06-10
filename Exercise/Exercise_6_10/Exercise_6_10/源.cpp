#if 0
#include<iostream>
using namespace std;

int count_cup(int cup)
{
	int ret = 0;
	while (cup >= 3)
	{
		ret += cup / 3;
		cup = cup % 3 + cup / 3;
	}
	return ret;
}
int main()
{
	int cup = 0;
	while (cin >> cup)
	{
		if (cup == 0)
			break;
		else
			cout << count_cup(cup) << endl;
	}
	return 0;
}
#endif
#include<iostream>
#include<string>
using namespace std;

string sublongstr(string s1, string s2)
{
	string ret;
	int i = 0;
	while (i<s1.size() && i<s2.size())
	{
		string temp;
		while (s1[i] == s2[i] && i<s1.size() && i<s2.size())
			temp += s1[i++];
		if (temp.size()>ret.size())
			ret = temp;
		++i;
	}
	return ret;
}

int main()
{
	string s1;
	string s2;
	while (getline(cin, s1))
	{
		getline(cin, s2);
		cout << sublongstr(s1, s2) << endl;
	}
	return 0;
}