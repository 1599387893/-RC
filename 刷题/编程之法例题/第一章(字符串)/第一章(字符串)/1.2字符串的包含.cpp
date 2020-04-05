//判断短字符串中的元素是否全部包含在长字符串中
#if 0
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//暴力法
bool StringContain1(string s1, string s2)
{
	for (int i = 0; i < s2.size(); ++i)
		if (s1.find(s2[i]) == string::npos)
			return false;
	return true;
}
//先排序再轮询
bool StringContain2(string s1, string s2)
{
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	for (int a = 0, b = 0; b < s2.size();)
	{
		while ((a < s1.size()) && (s1[a] < s2[b]))
			a++;
		if (a >= s1.size() || s1[a] > s2[b])
			return false;
		++b;
	}
	return true;
}
//素数相乘(针对每个字母用一个素数表示，将长串中每个数相乘，用短串中的字符除长串结果，判断是否有余数)
bool StringContain3(string s1, string s2)
{
	vector<int> p{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 6, 67, 71, 73, 79, 83, 89, 97, 101 };
	int all = 1;
	for (auto c : s1)
		all *= p[c - 'a'];
	for (auto c : s2)
		if (all%p[c - 'a'])
			return false;
	return true;
}

//位运算(使用一个散列表，保存长串出现的字符，遍历短串找散列表)
bool StringContain4(string s1, string s2)
{
	int hash = 0; //使用一个整数代替一个散列表
	for (int i = 0; i < s1.size(); ++i)
		hash |= (1<<(s1[i]-'a'));
	for (int i = 0; i < s2.size(); ++i)
		if ((hash  & (1 << (s2[i] - 'a'))) == 0)
			return false;
	return true;
}
int main()
{
	string s1 = "abcd",s2 = "ace";
	if (StringContain4(s1, s2))
		cout << "IsContain" << endl;
	else
		cout << "Not" << endl;
	system("pause");
	return 0;
}

#endif