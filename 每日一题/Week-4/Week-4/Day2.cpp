//1. 字符串反转
#if 0 
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
void Reverse(const char* s)
{
	if (*s == '\0')
		return;
	Reverse(s + 1);
	cout << *s;
}
int main()
{
	string s;
	while (cin >> s)
		Reverse(s.c_str());
	return 0;
}
#endif

//2. 公共子串计算
#if 0
#include<iostream>
#include<string>
using namespace std;
int SubstrLength(string& s1, string& s2)
{
	int ret = 0;
	for (size_t i = 0; i < s1.size() - ret; ++i)
	{
		int temp = 1;
		for (size_t j = i; j < s1.size(); ++j)
			if (s2.find(s1.substr(i, j - i + 1)) != string::npos)
				temp = j - i + 1;
		if (temp > ret)
			ret = temp;
	}
	return ret;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << SubstrLength(s1, s2) << endl;
	return 0;
}
#endif