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

