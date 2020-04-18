#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n = 0, m = 0;
	int Q = 0, q;
	int lose = 0; //亏损额
	cin >> n >> m;
	vector<int> arr(n, 0); //保存每支股票的每天亏损额
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	cin >> Q;
	Q = 2;
	while (Q--)
	{
		cin >> q;
		lose = 0;
		int day = 1;
		//如果要抛售的股票数==总的股票数，那么先抛售亏损额最大的；
		//如果抛售的股票数 < 总的股票数，那么抛售前q个，其中先抛售这q个中的最大的几个
		int sum = 0;
		int pos = 0;
		if (q >= n)
			pos = arr.size() - 1;//全部抛售；
		else
			pos = arr.size() - q;//只抛售一部分
		while (pos >= 0)
		{
			sum = 0;
			//循环一次就是一天要抛售的数
			for (int i = 0; i<m && pos >= 0; ++i)
				sum += arr[pos--];
			lose += sum*(day++);
		}
		cout << lose << endl;
	}
	return 0;
}
#endif
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int solve(vector<pair<int, int>>& v)
{
	sort(v.begin(), v.end());
	pair<int, int> temp = v[0];
}
/******************************结束写代码******************************/


int main() {
	int n = 0, start = 0, end = 0;
	cin >> n;
	vector<pair<int,int>> v;
	while (n--)
	{
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	cout << solve(v) << endl;
	return 0;

}
