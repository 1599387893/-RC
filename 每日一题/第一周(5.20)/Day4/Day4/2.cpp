//2
//�������ת��������һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN��������
//����ʾ����
//			7 2
//���ʾ����
//			111

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
	// ����Ǹ�������ת�������������һ��
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}
	// �����ƻ���ɶ�Ӧ���ַ���ӵ�s
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