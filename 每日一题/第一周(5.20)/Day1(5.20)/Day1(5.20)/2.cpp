//2
//ɾ�������ַ�
//����ʾ����
//			I am bboy. 
//			ab
//���ʾ����
//			I m oy

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	int hashtable[256] = { 0 };
	for (size_t i = 0; i < s2.size(); ++i)//ͳ��s2���ֵ��ַ�
		hashtable[s2[i]]++;

	string ret;
	for (size_t i = 0; i < s1.size(); ++i)
		if (hashtable[s1[i]] == 0)//���s1[i]���ַ�û�г�����s2�У��ͽ�����뵽ret��
			ret += s1[i];

	cout << ret << endl;

	system("pause");
	return 0;
}