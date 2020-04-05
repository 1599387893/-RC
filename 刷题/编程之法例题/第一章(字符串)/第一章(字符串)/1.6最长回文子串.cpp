#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


//中心扩展法
int LongestPalindrome1(const char* str, int n)
{
	if (str == nullptr || n < 1)
		return 0;
	int res = 0;
	for (int i = 1; i < n - 1 && res/2 <= (n-i); ++i) 
	{
		//已i作为中心位置，向两边查看是否为回文串，并保存回文串的长度
		//1.奇数回文串
		int left = i - 1;
		int right = i+1;
		int size = 1;
		//2.偶数回文串
		if (i + 1 < n && str[i + 1] == str[i])
		{
			right++;
			size++;
		}
		while (left >= 0 && right < n && str[left] == str[right])
		{
			size += 2;
			left--;
			right++;
		}
		res = max(size, res);
	}
	return res;
}
int LongestPalindrome2(const char* s, int n)
{
	int i, j, max, c;
	if (s == 0 || n < 1)
		return 0;
	max = 0;
	
	//i为回文的中心位置
	for (i = 0; i < n; ++i)
	{
		//回文长度为奇数
		for (j = 0; (i - j >= 0) && (i + j < n); ++j)
		{
			if (s[i - j] != s[i + j])
				break;
			c = j * 2 + 1;
			//c += 2;
		}
		if (c > max)
			max = c;
		//回文长度为偶数
		for (j = 0; (i - j >= 0) && (i + j + 1 < n); ++j)
		{
			if (s[i - j] != s[i + j + 1])
				break;
			c = j * 2 + 2;
		}
		if (c > max)
			max = c;
	}
	return max;
}
//2.Manacher算法

int main()
{
	string str = "efgabccbafadf";
	cout<<LongestPalindrome1(str.c_str(),str.size());
	string s = "abc" + 'd';
	cout << s << endl;
	return 0;
}