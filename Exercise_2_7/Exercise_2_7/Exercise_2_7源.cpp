#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;


//void mystrrev(char string[])
//{
//	assert(string);
//	if (*string == '\0' || *(string + 1) == '\0')
//		return;
//	else
//	{
//		char* start = string;
//		char* end = string;
//		char temp;
//		while ('\0' != *end++);
//		--end;
//		--end;
//		while (start < end)
//		{
//			temp = *start;
//			*start = *end;
//			*end = temp;
//			end--;
//			start++;
//		}
//		return;
//	}
//}
//int main()
//{
//	char s[] = "joker xue";
//	cout << s << endl;
//	mystrrev(s);
//	cout << s << endl;
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include<cstring>
//void GetMemory(char **p)
//{
//	*p = new char[100];
//}
//int main(void)
//{
//	char *str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	cout << str;
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//void GetMemory(char **p)
//{
//	*p = new char[100];
//}
//int main()
//{
//	char *str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	cout << str;
//	free(str);
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//char** GetMemory()
//{
//	char p[5] = { 'a', 'b', 'c', 'd', '\0' };
//	return p;
//}
//int main(void)
//{
//	char **str = NULL;
//	str = GetMemory();
//	cout << str;
//	system("pause");
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main(void)
//{
//	char *str = new char[100];
//	strcpy(str, "hello");
//	
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		cout << str;
//	}delete[] str;
//	return 0;
//}

//int main()
//{
//	int a = 15, b = 20;
//	 int c = 105;
//	 int *p1 = &c;
//	int * p2 = &b;
//	 int * p3 = &c;
//	p1 = &b;
//	*p1 = 100;
//	p2 = &a;
//	*p2 = a;
//	p3 = &b;
//	*p3 = 100;
//	return 0;
//}

//int main()
//{
//	char s[] = "Hello world";
//	char* ptr = s;
//	while (*ptr)
//		cout << " " << *ptr++;
//	system("pause");
//	return 0;
//}

