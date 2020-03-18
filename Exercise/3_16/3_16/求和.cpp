//#include<iostream>
//#include<vector>
//using namespace std;
//vector<vector<int>> res;
//void FindCount(vector<int> temp, const int m,int sum)
//{
//	if (sum==m)
//	{
//		res.push_back(temp);
//		return;
//	}
//	int gap = m - sum;
//	if (gap>temp[temp.size() - 1] && gap<m)
//	{
//		temp.push_back(gap);
//		FindCount(temp, m,sum+gap);
//	}
//}
//int main()
//{
//	int n, m;
//	while (cin >> n >> m)
//	{
//		res.clear();
//		for (int i = 1; i <= n && i <= m; ++i)
//		{
//			vector<int> temp{ i };
//			int sum = i;
//			FindCount(temp, m, sum);
//		}
//	}
//}

#include <iostream>
#include <vector>
using namespace std;

void GetFunc(int start, int n, int m, vector<int> v)
{
	//n:��1��n������
	//m:��ʾ�����ռ�
	if (m == 0)
	{
		for (int i = 0; i<v.size(); ++i)
			i == 0 ? cout << v[i] : cout << " " << v[i];
		cout << endl;
		return;
	}

	if (m < 0 || start>n)
		return;

	//Ҫ
	v.push_back(start);
	GetFunc(start + 1, n, m - start, v);

	//��Ҫ
	v.pop_back();
	GetFunc(start + 1, n, m, v);
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v;
		int start = 1;
		GetFunc(start, n, m, v);
	}
	return 0;
}