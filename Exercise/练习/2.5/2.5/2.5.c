// 5.求两个数的最大公约数。 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num1 = 0, num2 = 0;
	int i = 0, temp = 0;
	printf("请输入想要求最大公约数的两个值：");
	scanf("%d %d", &num1, &num2);
	if (num1 > num2)
	{
		temp = num2;
	}
	else
	{
		temp = num1;
	}
	for (i = temp; i > 0; i--)
	{
		if ((num1%temp == 0) && (num2%temp == 0))
		{
			printf("%d和%d的最大公约数为：%d\n", num1, num2, i);
			break;
		}
	}
	return 0;
}
