//1. 给定两个整形变量的值，将两个值的内容进行交换。 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 2, b = 3;
	int c = 0;
	printf("a=%d b=%d\n", a, b);
	c = a;
	a = b;
	b = c;
	printf("a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}
