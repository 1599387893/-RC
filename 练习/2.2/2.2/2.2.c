//2. ����������ʱ���������������������ݣ������⣩  
#include<stdio.h>
#include<stdlib.h>
int main()
{
	//����һ
	int a = 2, b = 3;
    printf("a=%d b=%d\n", a, b);
	a = a - b;
	b = b + a;
	a = b - a ;
	printf("a=%d b=%d\n", a, b);
	system("pause");

	//������
	//int a = 2, b = 3;
	//printf("a=%d b=%d\n", a, b);
	//a = a ^ b;
	//b = b ^ a;
	//a = b ^ a;
	//printf("a=%d b=%d\n", a, b);
	//system("pause");
	return 0;
}
