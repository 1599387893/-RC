#include<iostream>
#include<string>
using namespace std;

int TrsformToInt(string& s)
{
	int ret = 0;
	for (int i = s.size() - 1; i >= 0;--i)
	{
		if (s[i] == 'I')
		{
			if ((i + 1 <= s.size() - 1) && ('V' == s[i + 1]))
				ret -= 1;
			else if ((i + 1 <= s.size() - 1) && (s[i + 1] == 'X'))
				ret -= 1;
			else
				ret += 1;
		}
		else if (s[i] == 'X')
		{
			if ((i + 1 <= s.size() - 1) && s[i + 1] == 'L')
				ret -= 10;
			else if ((i + 1 <= s.size() - 1) && s[i + 1] == 'C')
				ret -= 10;
			else
				ret += 10;
		}
		else if (s[i] == 'C')
		{
			if ((i + 1 <= s.size() - 1) && s[i + 1] == 'D')
				ret -= 100;
			else if ((i + 1 <= s.size() - 1) && s[i + 1] == 'M')
				ret -= 100;
			else
				ret += 100;
		}
		else if (s[i] == 'V')
			ret += 5;
		else if (s[i] == 'L')
			ret += 50;
		else if (s[i] == 'D')
			ret += 500;
		else
			ret += 1000;
	}
	return ret;
}
int main()
{
	string s;
	while (cin >> s)
		cout << TrsformToInt(s) << endl;
	return 0;
}
