#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


//������չ��
int LongestPalindrome1(const char* str, int n)
{
	if (str == nullptr || n < 1)
		return 0;
	int res = 0;
	for (int i = 1; i < n - 1 && res/2 <= (n-i); ++i) 
	{
		//��i��Ϊ����λ�ã������߲鿴�Ƿ�Ϊ���Ĵ�����������Ĵ��ĳ���
		//1.�������Ĵ�
		int left = i - 1;
		int right = i+1;
		int size = 1;
		//2.ż�����Ĵ�
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
	
	//iΪ���ĵ�����λ��
	for (i = 0; i < n; ++i)
	{
		//���ĳ���Ϊ����
		for (j = 0; (i - j >= 0) && (i + j < n); ++j)
		{
			if (s[i - j] != s[i + j])
				break;
			c = j * 2 + 1;
			//c += 2;
		}
		if (c > max)
			max = c;
		//���ĳ���Ϊż��
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
//2.Manacher�㷨

int main()
{
	string str = "efgabccbafadf";
	cout<<LongestPalindrome1(str.c_str(),str.size());
	string s = "abc" + 'd';
	cout << s << endl;
	return 0;
}