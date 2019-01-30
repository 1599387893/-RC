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
//	cout << "圆的面积为：" << PI * r * r << endl;
//	cout << "圆的周长为：" << PI * 2 * r << endl;
//	system("pause");
//	return 0;
//}

//交换两个数字

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
	cout << n << "的阶乘为：" << factorial << endl;
	system("pause");
	return 0;
}