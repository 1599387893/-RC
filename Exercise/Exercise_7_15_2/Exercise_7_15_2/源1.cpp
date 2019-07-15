#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;


int find(char& a)
{
	if (a >= 'A' && a <= 'C')
		return 2;
	else if (a >= 'D' && a <= 'F')
		return 3;
	else if (a >= 'G' && a <= 'I')
		return 4;
	else if (a >= 'J' && a <= 'L')
		return 5;
	else if (a >= 'M' && a <= 'O')
		return 6;
	else if (a >= 'P' && a <= 'S')
		return 7;
	else if (a >= 'T' && a <= 'V')
		return 8;
	else 
		return 9;
}
string Number_Transform(string s)
{
	string pn;
	for (size_t i = 0; i<s.size(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			pn += s[i];
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			for (int i = 2; i<10; ++i)
			{
				if (find(s[i]))
					pn += (i + 48);
			}
		}
		else
			continue;
	}
	return pn;
}
int main()
{
	set<string, string> s;
	int n = 0;
	while (cin >> n)
	{
		while (n--)
		{
			string s1;
			cin >> s1;
			s1 = Number_Transform(s1);
			s.insert(s1,s1);
		}
		auto e = s.begin();
		while (e != s.end())
		{
			string ret;
			ret = *e;
			cout << ret[0] << ret[1] << ret[2] << "-" << ret[3] << ret[4] << ret[5] << ret[6] << endl;
		}
	}
	return 0;
}