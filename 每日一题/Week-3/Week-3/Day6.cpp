//1.统计每个月的兔子总数
#if 0
#include<iostream>
using namespace std;
int main()
{
	int month;
	while (cin >> month)
	{
		int a = 1, b = 0, c = 0;//分别表示一个月，两个月，三个月的兔子的个数
		while (--month)
		{
			c += b;
			b = a;
			a = c;
		}
		cout << a + b + c << endl;
	}
	return 0;
}
#endif
//2.字符串通配符
#if 0
#include<iostream>
#include<string>
using namespace std;
bool IsMatch(string& s1, string& s2, size_t i, size_t j)
{
	if (i == s1.size() && j == s2.size())
		return true;
	else if (i == s1.size() || j == s2.size())
		return false;
	else if (s1[i] == '?' || (s1[i] == s2[j]))
		return IsMatch(s1, s2, i + 1, j + 1);
	else if (s1[i] == '*')
		return IsMatch(s1, s2, i + 1, j) || IsMatch(s1, s2, i, j+1) || IsMatch(s1, s2,i+1,j+1);
	else
		return false;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << (IsMatch(s1, s2, 0, 0) ? "true" : "false") << endl;
	return 0;
}
#endif