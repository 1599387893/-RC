#include<iostream>
#include<cstring>
using namespace std;

#if 0
#define INT_PTR int*
typedef int* int_ptr;

int aaaa;

typedef struct
{
	int a;
	char b;
	short c;
	short d;
}AA_t;
int main()
{
#if 0
	int  a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 }, *q[4], k;
	for (k = 0; k < 4; ++k)
	{
		q[k] = &a[k * 3];
	}
	printf("%d\n",q[3][1]);

	system("pause");
	return 0;

	int i, j, a = 0;
	for ( i = 0; i < 2; ++i)
	{
		for (j = 0; j < 4;++j)
		{ 
			if (j % 2)
				break;
			++a;
		}
		a++;
	}
	cout << a << endl;
	system("pause");
	return 0;


	int a1;
	cout << a << endl;
	//cout << a1 << endl;


	cout << (0x13 & 0x17) << endl;
	cout << (0x13 | 0x17) << endl;


	int s[][2] = {1,2,3,4};
	int s1[2][2] = { 1,2,3,4 };


	cout << (sizeof(AA_t)) << endl;


	const char* p = "Hello!";
	printf("%c\n",*p);


	int a = 10;
	cout << (a+=a*=a-=a/3) << endl;
	system("pause");
#endif
	//char a = 'a';
	//int b = 1;
	//float c = 1;
	//double d = 1;
	//cout << typeid(a*b + d - c).name() << endl;
	//double 类型一般由精度最高的决定

	INT_PTR a, b;
	int_ptr c, d;
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	system("pause");
	return 0;
}
#endif

int arr[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
bool find_key(int key)
{
	int i = 0;
	int j = 3;
	while (i < 4 && j >= 0)
	{
		if (arr[i][j] == key)
			return true;
		else if (arr[i][j] > key)
		{
			j--;
			continue;
		}
		else
		{
			i++;
			continue;
		}
	}
	return false;
}
string Replace(char* s)
{
	int size = strlen(s);
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		if (s[i] == ' ')
			count++;
	}
	string ret;
	ret.resize(size + count * 2);
	int j = size + count * 2 - 1;
	for (int i = size - 1; i >= 0; i++)
	{
		if (s[i] == ' ')
		{
			ret[j--] = '0';
			ret[j--] = '2';
			ret[j--] = '%';
		}
		else
			ret[j--] = s[i];
	}
	return ret;
}
int main()
{
#if 0
	int col = 4;
	int row = 4;
	int key = 20;
	for (int i = 0; i < 16;i++)
	{
		key = **(arr + i);
		cout << "find key ;"<<key <<" return :"<< find_key(key) << endl;
	}
#endif
	
	char* str = "I am a good student";
	string ret = Replace(str);
	cout<<ret<<endl;
	system("pause");

	return 0;
}

