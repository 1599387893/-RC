//1.��ˮƿ
#if 0
#include<iostream>
using namespace std;
int Cups(int n)
{
	int ret = 0;
	int a, b;
	while (n>2)
	{
		a = n % 3; //һ�λ�ȡʣ��Ŀ�ƿ��
		b = n / 3; //һ�λ�ȡ��������
		ret += b;
		n = a + b;
	}
	if (n == 2)
		ret++;
	return ret;
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		cout << Cups(n) << endl;
	}
	return 0;
}
//��Ʒ�ⷨ
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		cout << n/2 << endl;
	}
	return 0;
}
#endif
//2.���������ַ���a,b�е�������Ӵ�
#if 0
#include<iostream>
#include<string>
using namespace std;
string MaxStr(string& s1, string& s2)
{
	string ret = "";
	if (s1.size() > s2.size())
		s1.swap(s2);
	for (int i = 0; i < s1.size(); ++i)
	{
		string temp;
		for (int j = i + ret.size(); j<s1.size(); j++)
			if (s2.find(s1.substr(i, j - i - 1)) != string::npos)
				temp = s1.substr(i, j - i - 1);
		if (temp.size() > ret.size())
			ret = temp;
	}
	return ret;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << MaxStr(s1, s2) << endl;
	return 0;
}
#endif