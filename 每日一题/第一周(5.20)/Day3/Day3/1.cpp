//1
//找出字符串中最长的数字串
//输入示例：
//			fasfa123faf4567fohki123456789
//输出示例：
//			123456789  
#if 0
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	string ret;
	string temp;

	for (int i = 0; i < str.size(); ++i)
	{
		while (str[i] >= '0'&& str[i] <= '9')
			temp += str[i++];
		if (ret.size() < temp.size())
			ret = temp;
		temp.clear();
	}
	cout << ret << endl;
	system("pause");
	return 0;
}


#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s, ret, temp;
	cin >> s;
	for (size_t i = 0; i <= s.size(); ++i)
	{
		if (s[i] >= '0'&& s[i] <= '9')
		{
			temp += s[i];
		}
		else
		{
			if (temp.size()>ret.size())
				ret = temp;
			else
				temp.clear();
		}
	}
	cout << ret << endl;
	system("pause");
	return 0;
}
#endif
