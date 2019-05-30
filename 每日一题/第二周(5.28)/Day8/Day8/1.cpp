//1
//两种排序方法（俩个字符串按照长度或者字符串的字典序排序）
//输入示例：
//			3
//			a
//			aa
//			bbb
//输出示例：
//			both

#if 0
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
	int x = 0;
	int y = 0;
	int n;
	string temp;
	cin >> n;

	vector<string> s;
	for (int i = 0; i<n; ++i)
	{
		cin >> temp;
		s.push_back(temp);
	}


	if (n == 1)
	{
		cout << "both" << endl;
		return 0;
	}
	for (int i = 0; i<n - 1; ++i)
	{
		if (s[i].size()>s[i + 1].size())
			x = 1;
		if (strcmp(s[i].c_str(), s[i + 1].c_str())>0)
			y = 1;
	}
	if (x == 0 && y == 0)
		cout << "both" << endl;
	else if (x == 1 && y == 0)
		cout << "lexicographically" << endl;
	else if (x == 0 && y == 1)
		cout << "lengths" << endl;
	else
		cout << "none" << endl;

	system("pause");
	return 0;
}

//方法二
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main()
{
	int flag = 2;
	int n;
	cin >> n;
	fflush(stdin);
	string* s = new string[n];
	for (int i = 0; i<n; ++i)
		getline(cin, s[i]);


	for (int i = 0; i<n - 1; ++i)
	{
		if (flag != -1 && (s[i].size()>s[i + 1].size()))
			if (flag == 0)
				flag = -1;
			else
				flag = 1;
		if (flag != -1 && (strcmp(s[i].c_str(), s[i + 1].c_str())>0))
			if (flag == 1)
				flag = -1;
			else
				flag = 0;
	}
	if (flag == 2)
		cout << "both" << endl;
	else if (flag == 1)
		cout << "lexicographically" << endl;
	else if (flag == 0)
		cout << "lengths" << endl;
	else
		cout << "none" << endl;

	delete[] s;
	system("pause");
	return 0;
}
#endif