#include<stdio.h>
#include<Windows.h>

#if 0
int CountBit1(int a)
{
	int ret = 0;
	for (int i = 0; i < a; ++i)
	{
		if ((a >> i) & 1)
			ret++;
	}
	return ret;
}
int CountBit2(int a)
{
	int ret = 0;
	while (a)
	{
		ret++;
		a = a&(a-1);
	}
	return ret;
}
int main()
{
#if 0
	int i = -1;
	printf("%d\n",(i << 3));
	printf("%d\n",(i>>3));

	int  a = 1;
	int b = 2;
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a= %d,b = %d\n",a,b);
	a = a - b;
	b = a - b;
	a = b - a;
	printf("a= %d,b = %d\n", a, b);
#endif
	printf("%d\n", CountBit1(18));
	printf("%d\n", CountBit1(17));
	system("pause");
	return 0;
}
#endif

void test1(int arr[])
{
	printf("%d\n", sizeof(arr));//(2)
}
void test2(char ch[])
{
	printf("%d\n", sizeof(ch));//(4)
}
int main()
{
#if 0
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%d\n", sizeof(arr));//(1)
	printf("%d\n", sizeof(ch));//(3)
	test1(arr);
	test2(ch); 
	
	int i = 0, a = 0, b = 2, c = 3, d = 4,e = 5;
	//i = a++ && ++b && d++;
	i = a++||++b||++d || e++;
	printf("a = %d\nb = %d\nc=%d\nd=%d\ne=%d\n", a, b, c, d,e);
#endif

#if 0
	char a = 0xb6;
	short b = 0xb600;
	int c = 0xb6000000;
	if (a == 0xb6)
		printf("a\n");
	if (b == 0xb600)
		printf("c\n");
	if (c == 0xb6000000)
		printf("c\n");

	int c = 2;
	printf("%d\nc=%d\n",(c+ --c),c);


	//判断大小端
	int  a = 1;
	char b = *((char*)&a);
	if (b == 1)
		printf("小");
	else
		printf("大");

	union
	{ 
		int i; 
		char c;
	} un;
	un.i = 1;
	if (un.c == 1)
		printf("小");
	else
		printf("大");


	//unsigned int j = -20;
	//printf("%d  %u\n",j,j);

	unsigned int i;
	for (i = 9; i >= 0; i--) {
		printf("%u\n", i);
	}
#endif
#if 0
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));  //16
	printf("%d\n", sizeof(a+0)); //4
	printf("%d\n", sizeof(*a)); //4
	printf("%d\n", sizeof(a+1)); //4
	printf("%d\n", sizeof(a[1])); //4
	printf("%d\n", sizeof(&a)); //4
	printf("%d\n", sizeof(*&a)); //4
	printf("%d\n", sizeof(&a+1)); //4
	printf("%d\n", sizeof(&a[0])); //4
	printf("%d\n", sizeof(&a[0]+2)); //4
#endif

#if 0
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr)); // 6
	printf("%d\n", sizeof(arr + 0)); //4
	printf("%d\n", sizeof(*arr)); //1
	printf("%d\n", sizeof(arr[1])); //1
	printf("%d\n", sizeof(&arr)); //4
	printf("%d\n", sizeof(&arr + 1)); //4
	printf("%d\n", sizeof(&arr[0] + 1)); //4

	printf("%d\n", strlen(arr)); //n
	printf("%d\n", strlen(arr + 0)); //n
//	printf("%d\n", strlen(*arr)); /
	//printf("%d\n", strlen(arr[1]));//5
	printf("%d\n", strlen(&arr)); //n
	printf("%d\n", strlen(&arr + 1)); //n
	printf("%d\n", strlen(&arr[0] + 1));//5
	system("pause");

#endif


	return 0;
}

