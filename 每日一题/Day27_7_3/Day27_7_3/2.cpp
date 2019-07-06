//三角形
//给定三角形的三条边，判断这三条边能不能构成三角形(1<=a,b,c<=10^100)


//解法一
//long double的范围是10^-4931 ~ 10^4932
#if 0
#include<iostream>
using namespace std;

int main()
{
	long double a = 0, b = 0, c = 0;
	while (cin >> a >> b >> c)
	{
		if ((a + b > c) && (a + c > b) && (b + c > a))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
#endif

#include<iostream>
#include<string>
using namespace std;

string add(string a, string b)
{
	int len1 = a.size();
	int len2 = b.size();
	string res = "";
	//从低位到高位逐位相加，在加的过程中注意字符和数字的转换和保存进位(t)
	int i,j,k,t = 0;
	for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; i--, j--)
	{
		//用k来接收第i位的数字加和的结果
		k = (a[i] - '0') + (b[j] - '0') + t;
		//将运算后的结果强转后保存到新res中
		res += (char)(k % 10 + '0');
		t = k / 10;
	}
	//a串未加完时
	while (i >= 0)
	{
		k = (a[i] - '0') + t;
		res += (char)(k % 10 + '0');
		t = k / 10;
		--i;
	}
	//b串未加完时
	while (j >= 0)
	{
		k = (b[j] - '0') + t;
		res += (char)(k % 10 + '0');
		t = k / 10;
		--j;
	}
	//将最后一次进位加入res中
	if (t > 0)
		res += (char)(t + '0');

	return res;
}
bool great(string a, string b)
{
	size_t len1 = a.size();
	size_t len2 = b.size();
	if (len1 > len2)
		return true;
	else if (len1 < len2)
		return false;
	else
		return (a > b);
}
int main()
{
	string a, b, c;
	while (cin >> a >> b >> c)
	{
		if (great(add(a, b), c) && great(add(a, c), b) && great(add(b, c), a))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}