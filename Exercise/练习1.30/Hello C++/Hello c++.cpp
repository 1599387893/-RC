#include<iostream>
using namespace std;

//int main()
//{
//	cout << "hello C++" << endl;
//	system("pause");
//	return 0;
//}

//const double PI = 3.1415;
//int main()
//{
//	int r = 0;
//	cin >> r;
//	cout << "Բ�����Ϊ��" << PI * r * r << endl;
//	cout << "Բ���ܳ�Ϊ��" << PI * 2 * r << endl;
//	system("pause");
//	return 0;
//}

//������������

//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> a >> b;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	system("pause");
//	return 0;
//}

int main()
{
	int n = 0;
	int i = 1;
	int factorial = 1;
	cin >> n;
	while (i <= n)
	{
		factorial *= i;
		i++;
	}
	cout << n << "�Ľ׳�Ϊ��" << factorial << endl;
	system("pause");
	return 0;
}