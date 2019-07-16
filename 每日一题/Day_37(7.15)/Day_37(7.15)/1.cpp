//1.电话号码
//将一串字符串转化为美国的电话号码的格式

//输入
//4
//UTT - HELP
//TUT - GLOP
//310 - GINO
//000 - 1213
//输出
//000-1213
//310 - 4466
//888 - 4357
//888 - 4567

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
		cout << endl;
		s.clear();
	}
	return 0;
}