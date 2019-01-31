#include<iostream>
using namespace std;

//斐波那契数列
//int main()
//{
//	int i = 0;
//	int f1 = 1, f2 = 1;
//	int sum = 2;
//	int num = 0;
//	cin >> i;
//	if (i == 1)
//	{
//		cout << "第" << i << "项为" << 1 << endl;
//		cout << "前" << i << "项和为" << 1 << endl;
//	}
//	else if (i == 2)
//	{
//		cout << "第" << i << "项为" << 1 << endl;
//		cout << "前" << i << "项和为" << 2 << endl;
//	}
//	else
//	{
//		int n = i-2;
//		while (n--)
//		{
//			num = f1 + f2;
//			sum += num;
//			f1 = f2;
//			f2 = num;
//		}
//		cout << "第" << i << "项为" << num << endl;
//		cout << "前" << i << "项和为" << sum << endl;
//	}
//	system("pause");
//	return 0;
//}

//判断奇偶
//int main()
//{
//	int num = 0;
//	cin >> num;
//
//	//1.0
//	//if (num % 2 == 0)
//	//	cout << "偶数" << endl;
//	//else
//	//	cout << "奇数" << endl;
//
//	//2.0
//	if (num & 1)
//		cout << "奇数" << endl;
//	else
//		cout << "偶数" << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int fib[20] = { 0, 1 };
//	int i = 0;
//	int sum = 2;
//	cin >> i;
//	while (i)
//	{
//		fib[i + 2] = fib[i] + fib[i + 1];
//		sum += fib[i + 2];
//		i--;
//	}
//	cout << sum;
//	system("pause");
//	return 0;
//}

#include <iostream>
using namespace std;
int main()
{
	int array[47];
	array[0] = 0;
	array[1] = 1;
	int i = 2, sum = 1, n, j, k;
	cout << "请输入项数n(最大值为47)：";
	cin >> n;
	do{
		j = i - 1;
		k = i - 2;
		array[i] = array[j] + array[k];
		sum += array[i];
		i += 1;
	} while (i<n);
	if (n == 1)
		sum = 0;
	if (n == 2)
		sum = 1;
	cout << "第" << n << "项为" << array[n - 1] << ",前" << n << "项和为" << sum;
	system("pause>nul");
	return 0;
}