#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include<iostream>
using namespace std;

int main()
{
#if 0
	int n = 100;
	int* ptr = &n;
	*ptr++;
	cout << n << endl;
#endif
	cout << (11 | 10) << endl;
	cout << (10 | 11) << endl;
	cout << (12 | 3) << endl;
	system("pause");
	return 0;
}

#include<Windows.h>
#include<stdio.h>
int main(){
	int a[100001], i, n, flag = 0, res = 1;
	for (scanf("%d", &n), i = 0; i<n; i++) scanf("%d", a + i);
	for (i = 1; i<n - 1; i++){
		if (a[i]>a[i - 1] && a[i]>a[i + 1]
			|| a[i]<a[i - 1] && a[i]<a[i + 1]){
			res++;
			if (n - 3 != i) i++;
		}
	}

	printf("%d\n", res);
	system("pause");
}
#endif

#if 0
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		// 注意这里多给了一个值，是处理越界的情况的比较，具体参考上面的解题思路
		vector<int> a;
		a.resize(n + 1);
		a[n] = 0;
		//读入数组
		int i = 0;
		for (i = 0; i < n; ++i)
			cin >> a[i];
		i = 0;
		int count = 0;
		while (i < n)
		{
			// 非递减子序列
			if (a[i] < a[i + 1])
			{
				while (i < n && a[i] < a[i + 1])
					i++;
				count++;
				i++;
			}
			else if (a[i] == a[i + 1])
			{
				i++;
			}
			else // 非递增子序列
			{
				while (i < n && a[i] > a[i + 1])
					i++;
				count++;
				i++;
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}
#endif
#if 0
#include <stdio.h> 
#include<Windows.h>

int main() 
{ 
#if 0
	char a[10]={ '1','2','3','4','5','6','7','8','9',0},*p; 
	printf("%s\n", a);
	int i; 
	i=8; 
	p=a+i; 
	printf("%s\n",p-3); 
	printf("%c\n", p);
#endif
	int i, j, k = 0;
	for (i = 0, j = -1; j = 1; ++i,++j)
		k++;
	printf("%d\n",k);
	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
	map<int, int> m;
	m.insert(make_pair(numbers[0], 1));
	for (size_t i = 1; i<numbers.size(); ++i)
	{
		if (m.find(numbers[i]) == m.end())
			m.insert(make_pair(numbers[i], 1));
		else
			m[numbers[i]]++;
	}
	for (auto it = m.begin(); it != m.end(); ++it)
		if (it->second > (numbers.size() / 2))
			return it->first;
	return 0;
}
int main()
{
	vector<int> v = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	cout << MoreThanHalfNum_Solution(v) << endl;
	system("pause");
	return 0;
}
#endif
