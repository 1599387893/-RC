#if 0
// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		string ja;
		int begin = 0;
		int end = 0;
		end = s.find('_', 0);
		while (end != -1)
		{
			s[end + 1] -= 32;
			ja.append(s.begin() + begin, s.begin() + end);
			begin = end + 1;
			end = s.find('_', begin);
		}
		ja.append(s.begin() + begin, s.end());
		cout << ja << endl;
	}
	return 0;
}
#endif

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		string rev;
		int start = s.size();
		int end = start - 1;
		for (; end >= 0; --end)
		{
			if ((!((s[end] >= 'A' && s[end] <= 'Z') || (s[end] >= 'a' && s[end] <= 'z'))) &&
				(!((s[end+1] >= 'A' && s[end+1] <= 'Z') || (s[end+1] >= 'a' && s[end+1] <= 'z'))))
			{
				start = end;
				continue;
			}
			if (!((s[end] >= 'A' && s[end] <= 'Z') || (s[end] >= 'a' && s[end] <= 'z')))
			{
				rev.append(s.begin() + end + 1, s.begin() + start);
				rev +=' ';
				start = end;
			}
		}
		rev.append(s.begin(), s.begin() + start);
		cout << rev << endl;
	}
	return 0;
}