//2
//删除公共字符
//输入示例：
//			I am bboy. 
//			ab
//输出示例：
//			I m oy

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	int hashtable[256] = { 0 };
	for (size_t i = 0; i < s2.size(); ++i)//统计s2出现的字符
		hashtable[s2[i]]++;

	string ret;
	for (size_t i = 0; i < s1.size(); ++i)
		if (hashtable[s1[i]] == 0)//如果s1[i]该字符没有出现在s2中，就将其加入到ret中
			ret += s1[i];

	cout << ret << endl;

	system("pause");
	return 0;
}