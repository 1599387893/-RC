//������
//���������ε������ߣ��ж����������ܲ��ܹ���������(1<=a,b,c<=10^100)


//�ⷨһ
//long double�ķ�Χ��10^-4931 ~ 10^4932
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
	//�ӵ�λ����λ��λ��ӣ��ڼӵĹ�����ע���ַ������ֵ�ת���ͱ����λ(t)
	int i,j,k,t = 0;
	for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; i--, j--)
	{
		//��k�����յ�iλ�����ּӺ͵Ľ��
		k = (a[i] - '0') + (b[j] - '0') + t;
		//�������Ľ��ǿת�󱣴浽��res��
		res += (char)(k % 10 + '0');
		t = k / 10;
	}
	//a��δ����ʱ
	while (i >= 0)
	{
		k = (a[i] - '0') + t;
		res += (char)(k % 10 + '0');
		t = k / 10;
		--i;
	}
	//b��δ����ʱ
	while (j >= 0)
	{
		k = (b[j] - '0') + t;
		res += (char)(k % 10 + '0');
		t = k / 10;
		--j;
	}
	//�����һ�ν�λ����res��
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