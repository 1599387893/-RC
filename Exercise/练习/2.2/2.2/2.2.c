//2. 不允许创建临时变量，交换两个数的内容（附加题）  
#include<stdio.h>
#include<stdlib.h>
int main()
{
	//方法一
	int a = 2, b = 3;
    printf("a=%d b=%d\n", a, b);
	a = a - b;
	b = b + a;
	a = b - a ;
	printf("a=%d b=%d\n", a, b);
	system("pause");

	//方法二
	//int a = 2, b = 3;
	//printf("a=%d b=%d\n", a, b);
	//a = a ^ b;
	//b = b ^ a;
	//a = b ^ a;
	//printf("a=%d b=%d\n", a, b);
	//system("pause");
	return 0;
}
