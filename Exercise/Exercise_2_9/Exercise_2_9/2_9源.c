#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//4.���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//int bit_diffrent1(int m, int n)
//{
//	int count = 0;
//	int ret = m ^ n;
//	while (ret)
//	{
//		ret = ret & (ret - 1);
//		count++;
//	}
//	return count;
//}
//
////int main()
////{
////	int m = 1;
////	int n = 5;
////	printf("%d\n", n>>1);
////	system("pause");
////	return 0;
////}
//int bit_diffrent2(int m, int n)
//{
//	int count = 0;
//	if (m < n)
//	{
//		int temp = m;
//		m = n;
//		n = temp;
//	}
//	while (m)
//	{
//		if ((m & 1) != (n & 1))
//			count++;
//		m /= 2;
//		n /= 2;
//	}
//	return count;
//}
////int main()
////{
////	int num1 = 0;
////	int num2 = 0;
////	printf("Please enter two numbers:");
////	scanf("%d %d", &num1, &num2);
////	printf("%d\n",bit_diffrent2(num1, num2));
////	system("pause");
////	return 0;
////}

//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
int fib(int n);
int fibdeep(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return (fibdeep(n - 1) + fibdeep(n - 2));
}
int fib(int n)
{
	int num1 = 1;
	int num2 = 1;
	int tmp = 0;
	int i = 0;
	if (n < 3)
	{
		return 1;
	}
	else
	{
		for (i = 0; i <= n - 3; i++)
		{
			tmp = num1 + num2;
			num1 = num2;
			num2 = tmp;
		}
		return tmp;
	}
}
int main()
{
	int n = 0;
	printf("Please enter a number for seach:");
	scanf("%d", &n);
	printf("%d\n",fibdeep(n));
	printf("%d\n",fib(n));
	system("pause");
	return 0;
}