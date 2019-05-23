//2
//倒置字符串（将一段字符串中的单词前后交换，以单词为单位）
//输入示例：
//			i like beijing
//输出示例：
//			beijing like i

#if 0
//方法一
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); ++i)
	{
		int j = i;
		while(s[j] != ' '&& j<s.size())
			++j;
		reverse(&s[i],&s[j]);
		i = j;
	}
	cout << s << endl;
	system("pause");
	return 0;
}


//方法二
#include <iostream>
#include <string>
using namespace std;

// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
		s2 = s1 + " " + s2;
	cout << s2 << endl;
	return 0;
}
#endif