#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//void Revers_Lift_Key(char* s, int k)
//{
//	assert(s);
//	int count = 0;
//	char* ptr = s;
//	char temp = 0;
//	if (NULL == *s || NULL == *(s+1) )
//		return;
//	while (*ptr++)
//		count++;
//	if (count < k)
//		return;
//	while (k--)
//	{
//		temp = *s;
//		ptr = s;
//		while (*(ptr+1))
//		{
//			*ptr = *(ptr + 1);
//			ptr++;
//		}
//		*ptr = temp;
//	}
//}
//int main()
//{
//	char s[] = "abcdefg";
//	int k = 0;
//	printf("%s\n", s);
//	printf("Please enter a number(Key):");
//	scanf("%d", &k);
//
//	Revers_Lift_Key(s, k);
//	printf("%s\n", s);
//	system("pause");
//	return 0;
//}

int Check_Its_Revers(char* s1, char* s2)
{
	assert(s1);
	assert(s2);
	int count1 = 0;
	int count2 = 0;
	count1 = strlen(s1);
	count2 = strlen(s2);
	if (count1 == count2 && count2 == 0)
		return 1;
	else if (count1 != count2)
		return -1;
	else
	{
		int i = 0;
		char temp = 0;
		char* ptr = NULL;
		while (i++<count1)
		{
			//移动一位
			temp = *s1;
			ptr = s1;
			while (*(ptr + 1))
			{
				*ptr = *(ptr + 1);
				ptr++;
			}
			*ptr = temp;
			//将s1和s2作比较
			if (strcmp(s1, s2) == 0)
				return 1;
		}
		return -1;
	}
}
int main()
{
	char s1[] = "abcdef";
	char s2[] = "defab";
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%d\n",Check_Its_Revers(s1, s2));
	system("pause");
	return 0;
}