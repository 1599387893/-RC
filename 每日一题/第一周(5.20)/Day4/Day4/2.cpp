//2
//�������ת��������һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN��������
//����ʾ����
//			7 2
//���ʾ����
//			111

//����һ
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
#endif

//������

//ȱ�ݣ�ֻ�ܱ�ʾʮ�������ڵ�
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

	//��n���Ƶ�ÿһλ���浽����v��
	for (int i = 0; m > 0; ++i)
	{
		v.resize(i + 1);
		v[i] = m%n;
		m /= n;
	}

	//������v�е�ֵ����ʮ���Ƶķ�ʽ�������
	for (int i = v.size() - 1; i >= 0; --i)
		retValue += v[i] * pow(10, i);

	if (flag)
		cout << "-";
	cout << retValue << endl;

	system("pause");
	return 0;

}