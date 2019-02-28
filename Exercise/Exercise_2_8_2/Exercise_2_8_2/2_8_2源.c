#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>


//实现n^k，使用递归法
//int Exposant(int n2, int k2)
//{
//	if (k2 == 0)
//		return 1;
//	else
//		return n2 * Exposant(n2, --k2);
//}
//int main()
//{
//	int n1 = 0;
//	int k1 = 0;
//	printf("输入n和k：");
//	scanf("%d %d", &n1, &k1);
//	printf("%d\n",Exposant(n1, k1));
//	system("pause");
//	return 0;
//}

//int DigitSum(int n)
//{
//	int sum = 0;
//	while (n / 10)
//	{
//		sum += n % 10;
//		n /= 10;
//	}
//	sum += n % 10;
//	return sum;
//
//}
//
//int main()
//{
//	int num = 0;
//	printf("Please enter a number:");
//	scanf("%d", &num);
//	printf("%d\n",DigitSum(num));
//	system("pause");
//	return 0;
//}


//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数 
//	int count = 0;
//
//	//1.0
//	//while (value)
//	//{
//	//	if (value % 2 == 1)
//	//		count++;
//	//	value /= 2;
//	//}
//
//    //2.0
//	//for (int i = 0; i < 32;i++)
//	//{
//	//	if ((value >> i) & 1 == 1)
//	//		count++;
//	//}
//
//	//3.0
//	while (value)
//	{
//		value = value & (value - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	unsigned int num = 0;
//	printf("Please enter a number:");
//	scanf("%d", &num);
//	printf("%d\n",count_one_bits(num));
//	system("pause");
//	return 0;
//}

//求出两个数的最大公约数
//int main()//1.0
//{
//	int num1 = 0;
//	int num2 = 0;
//	int num3 = 0;
//	printf("Please enter two numbers:");
//	scanf("%d %d", &num1,&num2);
//	do
//	{
//		num3 = num1 % num2;
//		num1 = num2;
//		num2 = num3;
//	} while (num3 != 0);
//	printf("最大公约数为:%d\n", num1);
//	system("pause");
//	return 0;
//}
//2.0
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int num = 0;
//	printf("Please enter two numbers:");
//	scanf("%d %d", &a, &b);
//	if (a < b)
//	{
//		num = a;
//		a = b;
//		b = num;
//	}
//	for (num = b; num>0; num--)
//	{
//		if ((a % num == 0) && (b % num == 0))
//			break;
//	}
//		printf("最大公约数为：%d\n", num);
//
//	system("pause");
//	return 0;
//}