#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

//二进制插入
#if 0
int main()
{
	int n, m;
	int i, j;
	while (cin >> n >> m >> j >> i)
	{
		n += (m << j);
		cout << n << endl;
	}
	return 0;
}
#endif
bool IsPrime(int& n)
{
	int m = sqrt(n);
	for (int i = 2; i <= m; ++i)
		if (n % i == 0)
			return false;
	return true;
}
void ParseNumber(int& n)
{
	int left = n / 2;
	int right = n - left;
	while (left > 1 && right < n)
	{
		if (IsPrime(left) && IsPrime(right))
			break;
		left--;
		right++;
	}
	cout << left <<endl << right << endl;
}
#if 0
int main()
{
	int n;
	while (cin >> n)
		ParseNumber(n);
	return 0;
}
#endif

struct str_t
{
	long long len;
	char data[32];
};
struct data1_t
{
	long long len;
	int data[2];
};
struct  data2_t
{
	long long len;
	char* data[1];
};
struct data3_t
{
	long long len;
	void* data[];
};

int main(void)
{
	struct str_t str;
	memset((void*)&str, 0, sizeof(struct str_t));
	str.len = sizeof(struct str_t) - sizeof(int);
	printf(str.data,str.len,"hello");
	struct data3_t* pData = (struct data3_t*)&str;
	printf("data:%s%s\n",str.data);
	system("pause");
	return 0;
}