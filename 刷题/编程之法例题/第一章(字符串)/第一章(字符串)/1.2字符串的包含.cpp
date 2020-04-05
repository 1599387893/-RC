//�ж϶��ַ����е�Ԫ���Ƿ�ȫ�������ڳ��ַ�����
#if 0
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//������
bool StringContain1(string s1, string s2)
{
	for (int i = 0; i < s2.size(); ++i)
		if (s1.find(s2[i]) == string::npos)
			return false;
	return true;
}
//����������ѯ
bool StringContain2(string s1, string s2)
{
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	for (int a = 0, b = 0; b < s2.size();)
	{
		while ((a < s1.size()) && (s1[a] < s2[b]))
			a++;
		if (a >= s1.size() || s1[a] > s2[b])
			return false;
		++b;
	}
	return true;
}
//�������(���ÿ����ĸ��һ��������ʾ����������ÿ������ˣ��ö̴��е��ַ�������������ж��Ƿ�������)
bool StringContain3(string s1, string s2)
{
	vector<int> p{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 6, 67, 71, 73, 79, 83, 89, 97, 101 };
	int all = 1;
	for (auto c : s1)
		all *= p[c - 'a'];
	for (auto c : s2)
		if (all%p[c - 'a'])
			return false;
	return true;
}

//λ����(ʹ��һ��ɢ�б����泤�����ֵ��ַ��������̴���ɢ�б�)
bool StringContain4(string s1, string s2)
{
	int hash = 0; //ʹ��һ����������һ��ɢ�б�
	for (int i = 0; i < s1.size(); ++i)
		hash |= (1<<(s1[i]-'a'));
	for (int i = 0; i < s2.size(); ++i)
		if ((hash  & (1 << (s2[i] - 'a'))) == 0)
			return false;
	return true;
}
int main()
{
	string s1 = "abcd",s2 = "ace";
	if (StringContain4(s1, s2))
		cout << "IsContain" << endl;
	else
		cout << "Not" << endl;
	system("pause");
	return 0;
}

#endif