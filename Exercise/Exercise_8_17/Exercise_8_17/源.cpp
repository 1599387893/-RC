#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>


int main()
{
#if 0
	int c[] = { 1, 3, 5 };
	int *k = c + 1;
	//printf("%d\n", *k);
	//printf("%d\n", *++k);
	printf("%d\n", *(++k));
	//printf("%d\n", *(k++));
	//printf("%d\n", ++(*k));
	//printf("%d\n", (*k)++);

	int a = 111;
	int *p1 = &a, *p2;
	p2 = p1;
	printf("%d %d\n", *p1, *p2);

	struct student
	{
		char name[10];
		int age;
		char gender;
	}std[3],*p = std;

	scanf("%d\n",&(*p).age );
	scanf("%d\n",&(std[0]).gender );
	scanf("%d\n",&(p->gender) );
	//scanf("%d\n",&std.name );

	int a = 2,*p1,**p2;
	p2 = &p1;
	p1 = &a;
	a++;
	printf("%d %d\n",*p1,**p2);

	int k, j, s;
	for (k = 2; k < 6; k++, k++)
	{
		s = 1;
		for (j = k; j < 6; ++j)
			s += j;
	}
	printf("%d\n",s);

	unsigned int a = 0xFFFFFFF7;
	unsigned char i = (unsigned int)a;
	char* b = (char*)&a;
	printf("%08x,%08x\n",i,*b);
#endif

	int x = 1, y = 012;
	printf("%d\n", y );
	printf("%d\n", y*x++);

	system("pause");
	return 0;
}