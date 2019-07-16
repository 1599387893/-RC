#include<iostream>
#include<set>
#include<string>
using namespace  std;
int main()
{
	set<string> s;
	int n = 0;
	while (cin >> n)
	{
		string str;
		string keyboard = "22233344455566677778889999";
		while (n--)
		{
			cin >> str;
			int lzf = 0;
			string ret;
			for (int i = 0; i<str.size(); ++i)
			{

				if (lzf == 3)
				{
					ret += '-';
					lzf++;
				}
				if (str[i] >= '0' && str[i] <= '9')
				{
					ret += str[i];
					lzf++;
				}
				else if (str[i] >= 'A' && str[i] <= 'Z')
				{
					ret += (keyboard[str[i] - 'A']);
					lzf++;
				}
			}
			s.insert(ret);
		}
		for (set<string>::iterator it = s.begin(); it != s.end(); it++)
			cout << *it << endl;
	}
	return 0;
}