#include<iostream>
#include<string>
using namespace std;

bool Judge(string s1, string s2)
{
	int size1 = s1.size();
	int size2 = s2.size();
	int i = 0;
	int j = 0;
	while (i<size1 && j<size2)
	{
		if ((s1[i] != s2[j]) && (s1[i] != '*') && (s1[i] != '?'))
			return false;
		if (s1[i] == '?')
		{
			++i;
			++j;
			continue;
		}
		if (s1[i] == '*')
		{
			++i;
			while (s1[i] != s2[j] && j<size2)
				++j;
		}
		++i;
		++j;
	}
	return true;
}
int main()
{
	string s1;
	string s2;
	while (getline(cin, s1))
	{
		getline(cin, s2);
		bool ret = Judge(s1, s2);
		if (ret == true)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}