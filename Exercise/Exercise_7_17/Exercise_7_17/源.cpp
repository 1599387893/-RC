#if 0
// write your code here cpp
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	map<char, int> m;//将A盒中的先插入m1中，接收B盒后，
	//在m1中查找是否有该元素，如果有，将计数的value--，
	//如果没有，输出NO；
	string a;
	string b;
	while (cin >> a >> b)
	{
		if (a.size() < b.size())
		{
			cout << "No" << endl;
			continue;
		}
		for (size_t i = 0; i<a.size(); ++i)
		{
			map<char, int>::iterator it;
			it = m.find(a[i]);
			//判断该元素是否在map中
			if (it != m.end())
				(*it).second++;
			else
				m.insert(pair<char, int>(a[i], 1));
		}
		size_t i = 0;
		for (; i<b.size(); ++i)
		{
			map<char, int>::iterator it;
			it = m.find(b[i]);
			if (it != m.end())
			{
				(*it).second--;
				if ((*it).second < 0)
				{
					cout << "No" << endl;
					break;
				}
			}
			else//m中没有该元素
			{
				cout << "No" << endl;
				break;
			}
		}
		if (i == b.size())
			cout << "Yes" << endl;
	}
	return 0;
}
#endif 

#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
bool Judge_bro(string str1, string str2)
{
	string s1 = str1;
	string s2 = str2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if (s1 == s2 && str1 != str2)
		return true;
	else
		return false;
}
int Find_bro(set<string>zd, string bro, int& n, string& ret)
{
	//用来计算兄弟单词的个数
	int count = 0;
	for (auto& e : zd)
	{
		if (Judge_bro(e, bro))
			count++;
		if (count == n)
			ret = e;
	}
	return count;
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n < 0 || n>1000)
			continue;
		string str;
		string bro;
		set<string> zd;
		//保存字典
		while (n--)
		{
			cin >> str;
			zd.insert(str);
		}
		cin >> bro >> n;
		string brostr;
		cout << Find_bro(zd, bro, n, brostr) << endl;
		cout << brostr << endl;
	}
	return 0;
}