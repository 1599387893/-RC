//2
//任意进制转换（给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数）
//输入示例：
//			7 2
//输出示例：
//			111

//方法一
#if 0
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;
	// 如果是负数，则转成正数，并标记一下
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}
	// 按进制换算成对应的字符添加到s
	while (m)
	{
		s += table[m%n];
		m /= n;
	}
	if (flag)
		s += '-';
	reverse(s.begin(), s.end());
	cout << s << endl;

	system("pause");
	return 0;
}
#endif

//方法二

//缺陷：只能表示十进制以内的
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
	int retValue = 0;
	int m, n;
	int flag = 0;
	vector<int>v;
	cin >> m >> n;

	if (m < 0)
	{
		flag = 1;
		m = 0 - m;
	}

	//将n进制的每一位保存到容器v中
	for (int i = 0; m > 0; ++i)
	{
		v.resize(i + 1);
		v[i] = m%n;
		m /= n;
	}

	//将容器v中的值按照十进制的方式组合起来
	for (int i = v.size() - 1; i >= 0; --i)
		retValue += v[i] * pow(10, i);

	if (flag)
		cout << "-";
	cout << retValue << endl;

	system("pause");
	return 0;

}