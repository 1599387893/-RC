////判案 
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i = 0;
//	int A = 0, B = 0, C = 0, D = 0, E = 0;
//	for (A = 1; A <= 5; A++)
//	{
//		for (B = 1; B <= 5; B++)
//		{
//			for (C = 1; C <= 5; C++)
//			{
//				for (D = 1; D <= 5; D++)
//				{
//					for (E = 1; E <= 5; E++)
//					{
//						if ((2 == B) + (3 == A) == 1)
//							//if ((2 == B && 3 != A) || (2 != B && 3 == A) == 1)
//						{
//							if ((2 == B) + (4 == E) == 1)
//								//if ((2 == B && 4 != E) || (2 != B && 4 == E) == 1)
//							{
//								if ((1 == C && 2 != D) || (1 != C && 2 == D) == 1)
//									//
//								{
//									if ((5 == C && 3 != D) || (5 != C && 3 == D) == 1)
//										//
//									{
//										if ((4 == E && 1 != A) || (4 != E && 1 == A) == 1)
//											//
//										{
//											if ((A*B*C*D*E) == 120)
//											{
//												printf("A:%d  B:%d  C:%d  D:%d  E:%d\n", A, B, C, D, E);
//											}
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char killer;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if (((killer != 'A') + ( killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
//		{
//			printf("杀手是：%c\n", killer);
//		}
//	}
//
//	system("pause");
//	return 0;
//}

//在屏幕上打印杨辉三角。 
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void Triangle1(const int n)
{
	int i = 0, j = 0;
	int a[20][20] = { 0 };
	for (i = 0; i < n; i++)
	{
		a[i][0] = 1;//每行的第一个为1
		//a[i][i] = 1;//每行的最后一个都为1
	}
	for (i = 0; i < n; i++)
	{
		printf("%-4d ", a[i][0]);
		for (j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			printf("%-4d ", a[i][j]);
		}
		printf("\n");
	}



	return;
}

void Triangle3(const int n)
{
	int i = 0, j = 0;
	int a[20][20] = { 0 };
	for (i = 0; i < n; i++)
	{
		a[i][0] = 1;//每行的第一个为1
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4 * (n - i) / 2; j++)
		{
			printf(" ");
		}
		printf("%-4d ", a[i][0]);
		for (j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			printf("%-4d ", a[i][j]);
		}
		printf("\n");
	}



	return;
}


void Triangle2(const int n)
{
	int i = 0, j = 0, l, r;
	int a[20] = { 0, 1 };
	for (i = 1; i <= n; i++)
	{
		l = 0;
		for (j = 1; j <= i; j++)
		{
			r = a[j];
			a[j] = l + r;
			l = r;
			printf("%d ", a[j]);
		}
		printf("\n");
	}
}

int main()
{
	int n = 0;
	printf("请输入想要打印的行数：");
	scanf("%d", &n);
	printf("打印杨辉三角\n");
	Triangle2(n); 
	printf("打印杨辉三角\n");
	Triangle3(n);
	system("pause");
	return 0;
}