// 3.求10 个整数中最大值。 
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[10] = {10,11,12,13,14,15,16,17,18,19};
	int max = 0,i = 0;
	for (i; i < 10; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
	}
	printf("最大值为：%d\n", max);
	system("pause");

	//(2)

	//int a[10] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	//int max = 0, i = 0,size = 0;
	//size = sizeof(a) / sizeof(int);
	//for (i; i < size; i++)
	//{
	//	if (a[i]>max)
	//	{
	//		max = a[i];
	//	}
	//}
	//printf("最大值为：%d\n", max);
	//system("pause");

    
	return 0;
}
