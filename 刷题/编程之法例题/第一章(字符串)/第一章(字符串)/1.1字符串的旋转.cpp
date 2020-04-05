#if 0

#include<stdio.h>
#include<Windows.h>

//方法一： 暴力法
void LeftShiftOne(char* str,int n)
{
	char temp = *str;
	for (int i = 0; i < n - 1; ++i,str++)
		*str = *(str + 1);
	*str = temp;
}
void Fun1(char* str,int n,int m)
{
	for (int i = 0; i < m; ++i)
		LeftShiftOne(str, n);
}
void swap(char* c1, char* c2)
{
	char temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}
//三步反转
void ReverseString(char* str, int begin, int end)
{
	while (begin < end)
		swap(str+(begin++), str+(end--));
}
void Fun2(char* str,int n,int m)
{
	ReverseString(str,0,n-1);
	ReverseString(str,0,m-1);
	ReverseString(str,m,n-1);
}
int main()
{
	char str[] = "abcdef";
	//Fun1(str,6,3);
	Fun2(str, 6, 3);
	printf("%s\n",str);
	system("pause");
	return 0;
}
#endif