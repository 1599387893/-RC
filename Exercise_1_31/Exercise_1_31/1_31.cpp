#include<iostream>
using namespace std;

//쳲���������
//int main()
//{
//	int i = 0;
//	int f1 = 1, f2 = 1;
//	int sum = 2;
//	int num = 0;
//	cin >> i;
//	if (i == 1)
//	{
//		cout << "��" << i << "��Ϊ" << 1 << endl;
//		cout << "ǰ" << i << "���Ϊ" << 1 << endl;
//	}
//	else if (i == 2)
//	{
//		cout << "��" << i << "��Ϊ" << 1 << endl;
//		cout << "ǰ" << i << "���Ϊ" << 2 << endl;
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
//		cout << "��" << i << "��Ϊ" << num << endl;
//		cout << "ǰ" << i << "���Ϊ" << sum << endl;
//	}
//	system("pause");
//	return 0;
//}

//�ж���ż
//int main()
//{
//	int num = 0;
//	cin >> num;
//
//	//1.0
//	//if (num % 2 == 0)
//	//	cout << "ż��" << endl;
//	//else
//	//	cout << "����" << endl;
//
//	//2.0
//	if (num & 1)
//		cout << "����" << endl;
//	else
//		cout << "ż��" << endl;
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
	cout << "����������n(���ֵΪ47)��";
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
	cout << "��" << n << "��Ϊ" << array[n - 1] << ",ǰ" << n << "���Ϊ" << sum;
	system("pause>nul");
	return 0;
}