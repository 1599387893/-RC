#if 0
// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

void Translate(string& s)
{
	size_t len = s.size();
	for (int i = 0; i<len; ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i] - 5<'A')
				s[i] = 'Z' - ('A' - (s[i] - 4));

			else
				s[i] = s[i] - 5;
		}
	}
	cout << s << endl;
}

int main()
{
	string s;
	while (getline(cin, s))
		Translate(s);
	return 0;
}
#endif