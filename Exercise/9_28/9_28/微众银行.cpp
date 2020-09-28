#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int number = 0;
	while (q--)
	{
		cin >> number;
		int gap = 1e8;
		int pos = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			n = abs(arr[i] - number);
			if (gap > n)
			{
				gap = n;
				pos = i;
			}
		}
		cout << arr[pos] << endl;
	}
	return 0;
}
#endif

#if 1
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void RotaL(vector<vector<int>>& arr)
{
	vector<vector<int>> temp(arr[0].size(), vector<int>(arr.size()));
	int row = 0, col = 0;
	for (int i = 0; i < temp.size(); ++i)
	{
		col = i;
		row = arr.size() - 1;
		for (int j = 0; j < temp[0].size(); ++j)
		{
			temp[i][j] = arr[row--][col];
		}
	}
	arr = temp;
}
void ReverLevel(vector<vector<int>>& arr)
{
	int begin = 0;
	int end = arr[0].size() - 1;
	for (int i = 0; i < arr.size(); ++i)
	{
		begin = 0;
		end = arr[i].size() - 1;
		while (begin < end)
			swap(arr[i][begin++], arr[i][end--]);
	}
}
void ReverVer(vector<vector<int>>& arr)
{
	int top = 0;
	int botton = 0;
	for (int i = 0; i < arr[0].size(); ++i)
	{
		top = 0;
		botton = arr.size() - 1;
		while (top < botton)
			swap(arr[top++][i], arr[botton--][i]);
	}
}
void RotaR(vector<vector<int>>& arr)
{
	vector<vector<int>> temp(arr[0].size(), vector<int>(arr.size()));
	int row = 0, col = 0;
	for (int i = 0; i < temp.size(); ++i)
	{
		col = arr[0].size() - 1 - i;
		row = 0;
		for (int j = 0; j < temp[0].size(); ++j)
		{
			temp[i][j] = arr[row++][col];
		}
	}
	arr = temp;
}
int main()
{
	int x = 0, y = 0, z = 0;
	int n = 0, m = 0, q = 0;
	int row = 0, col = 0;
	cin >> x >> y >> z;
	x %= 4;
	y %= 2;
	z %= 4;
	cin >> n >> m;
	cin >> q;
	unordered_map<int, pair<int,int>> um;
	vector<vector<int>> arr(n, vector<int>(m));
	int pos = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			arr[i - 1][j - 1] = pos++;
	//while (x--)
	//	RotaL(arr);
	while (y--)
		ReverLevel(arr);
	while (z--)
		RotaR(arr);
	for (int i = 0; i < arr.size(); ++i)
		for (int j = 0; j < arr[0].size(); ++j)
			um[arr[i][j]] = make_pair(i, j);
	while (q--)
	{
		cin >> row >> col;
		cout << um[row * m + col].first << " " << um[row * m + col].first << endl;
	}
	return 0;
}
#endif 



#if 0
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int A = 0, count = 0;
	cin >> A;
	vector<int> arr(A);
	map<int, int> m;
	for (int i = 0; i < A; ++i)
	{
		cin >> arr[i];
		m[arr[i]]++;
	}
	for (auto p : m)
		count += (p.second - 1);
	cout << (m.size() * (m.size() - 1) * (m.size() - 2)) / 6 + count << endl;
	return  0;
}
#endif