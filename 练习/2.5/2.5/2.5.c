// 5.�������������Լ���� 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num1 = 0, num2 = 0;
	int i = 0, temp = 0;
	printf("��������Ҫ�����Լ��������ֵ��");
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
			printf("%d��%d�����Լ��Ϊ��%d\n", num1, num2, i);
			break;
		}
	}
	return 0;
}
