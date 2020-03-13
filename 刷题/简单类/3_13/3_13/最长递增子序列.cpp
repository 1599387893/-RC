#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//暴力求解法
#if 0
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		vector<int> lis(n,0);
		int max_all = 1;
		for (int i = 1; i < n; ++i)
		{
			int max_item = 0;
			for (int j = 0; j < i; ++j)
			{
				if (arr[i]>arr[j])
					max_item = lis[j]>max_item ? lis[j] : max_item;
			}
			lis[i] = max_item + 1;
			if (max_all < lis[i])
				max_all = lis[i];
		}
		cout << max_all << endl;
	}
	return;
}
#endif

//动态规划

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> arr(n);
		vector<int> lis(n, 1);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (arr[i]>arr[j])
					lis[i] = max(lis[i], lis[j] + 1);
		sort(lis.begin(), lis.end());
		/*
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (arr[i]>arr[j] && lis[i]<=lis[j])
					lis[i] = lis[j] + 1;
		*/
		
		cout << lis[n - 1] << endl;
	}
	return 0;
}

//解法三 ： 转换成最长公共子序列求解
