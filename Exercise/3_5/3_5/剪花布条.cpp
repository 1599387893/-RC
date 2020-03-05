#if 0
// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int count = 0;
		auto begin = s.find(t, 0);
		while (begin != string::npos)
		{
			begin += t.size();
			count++;
			begin = s.find(t, begin);
		}
		cout << count << endl;
	}
	return 0;
}
#endif