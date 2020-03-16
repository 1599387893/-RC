////////#include<iostream>
////////#include<vector>
////////using namespace std;
////////
////////int n;
////////int FindWay(vector<vector<char>>& arr, int x, int y)
////////{
////////	if (x>1 || y >= n)
////////		return 0;
////////	if (arr[x][y] == 'X')
////////		return 0;
////////	if (x == 1 && y == n - 1)
////////		return 1;
////////	if (x == 1 && y<n - 1)
////////		return FindWay(arr, x - 1, y + 1) + FindWay(arr, x, y + 1);
////////	return FindWay(arr, x, y + 1) + FindWay(arr, x + 1, y + 1);
////////}
////////int main()
////////{
////////	while (cin >> n)
////////	{
////////		vector<vector<char>> way(2, vector<char>(n));
////////		//接收数据
////////		for (int i = 0; i < 2 * n; ++i)
////////			cin >> way[i / n][i % n];
////////		int ret = FindWay(way, 0, 0);
////////		ret == 0 ? cout << -1 << endl : cout << ret << endl;
////////	}
////////	return 0;
////////}
//////
//////#include<iostream>
//////#include<vector>
//////#include<map>
//////using namespace std;
//////
//////int ManyNum(vector<int>& arr)
//////{
//////	map<int, int> m;
//////	int max = 0;
//////	for (auto n : arr)
//////	{
//////		m[n]++;
//////		if (max < m[n])
//////			max = m[n];
//////	}
//////	return max;
//////}
//////int main()
//////{
//////	int n, x;
//////	cin >> n >> x;
//////	vector<int> arr(n);
//////	vector<int> temp(arr);
//////	for (int i = 0; i < n; ++i)
//////	{
//////		cin >> arr[i];
//////		temp[i] = x | arr[i];
//////	}
//////	int num1 = ManyNum(arr);
//////	int num2 = ManyNum(temp);
//////	num1 > num2 ? cout << num1 << endl : cout << num2 << endl;
//////	
//////	return 0;
//////}
////
////#include<iostream>
////#include<cmath>
////using namespace std;
////
////
////int main()
////{
////	cout << pow(3, 9) << endl;
////	int n, k, L, R;
////	cin >> n >> k >> L >> R;
////	int count = 0;
////	for (int i = L; i <= R; ++i)
////		if (i%k == 0)
////			count++;
////	cout << pow(count,n)<< endl;
////	return 0;
////}
//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//
//
//int main()
//{
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<int> pay(n);
//	vector<int> scouce(n);
//	multimap<int, int> way;
//	for (int i = 0; i < n; ++i)
//		cin >> scouce[i];
//	int u, v;
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> u >> v;
//		way.insert(pair<int,int>(u,v));
//	}
//	//遍历建厂的位置
//	for (int i = 0; i < n; ++i)
//	{
//		int temp = 0;
//
//	}
//
//
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;

int n;
int FindWay(vector<vector<char>>& arr, int x, int y)
{
	if (x>1 || y >= n || arr[x][y] == 'X')
		return 0;
	if (x == 1 && y == n - 1)
		return 1;
	if (x == 1 && y<n - 1)
		return FindWay(arr, x - 1, y + 1) + FindWay(arr, x, y + 1);
	return FindWay(arr, x, y + 1) + FindWay(arr, x + 1, y + 1);
}
int main()
{
	cin >> n;
	vector<vector<char>> way(2, vector<char>(n));
	//接收数据
	for (int i = 0; i < 2 * n; ++i)
		cin >> way[i / n][i%n];
	if (way[1][n - 1] == 'X')
	{
		cout << -1 << endl;
		return 0;
	}
	int ret = FindWay(way, 0, 0);
	ret == 0 ? cout << -1 << endl : cout << ret << endl;
	return 0;
}