#if 1
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	int temp = 0;
	set<int> arr;
	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		arr.insert(temp);
	}
	set<int> res;
	for (auto y : arr)
	{
		for (int i = 2; i <= n; ++i)
			if (i % y == 0)
				res.insert(i);
	}
	cout << res.size() << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n, -1));
	for (int i = 0; i < n; ++i)
	{
		board[i][i] = 0;
		board[i][n - i - 1] = 0;
		if (n % 2)
		{
			board[n / 2][i] = 0;
			board[i][n / 2] = 0;
		}
	}
	//将矩阵分为四个部分
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j] == 0)
				continue;
			if ((i < (n / 2)) && (j < (n / 2))) //左上角
			{
				if (i > j) board[i][j] = 3;
				else board[i][j] = 2;
			}
			if ((i < (n / 2)) && (j >= (n / 2))) //右上角
			{
				if (i + j < n) board[i][j] = 1;
				else board[i][j] = 8;
			}
			if ((i >= (n / 2) && (j < (n / 2)))) //左下角
			{
				if (i + j < n) board[i][j] = 4;
				else board[i][j] = 5;
			}
			if ((i >= (n / 2)) && (j >= (n / 2))) //右下角
			{
				if (i < j) board[i][j] = 7;
				else board[i][j] = 6;
			}
		}
	}
	for (auto arr : board)
	{
		for (auto a : arr)
			cout << a << " ";
		cout << endl;
	}
	return 0;
}
#endif



#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> Map;
int n;
int m;

int CountNumOfTeam(int row, int col)
{
	if (row < 0 || row >= n || col < 0 || col > m || Map[row][col] == 0)
		return 0;
	int count = 1;
	count += CountNumOfTeam(row - 1, col);
	count += CountNumOfTeam(row + 1, col);
	count += CountNumOfTeam(row, col - 1);
	count += CountNumOfTeam(row, col + 1);
	return count;
}
int MaxSolider()
{
	//先计算出每个位置所在队伍的士兵的人数
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			Map[i][j] = CountNumOfTeam(i, j);
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		for (int j = 0; j < m; ++j)
		{
			if (Map[i][j] == 0)
				continue;
			temp = 0;
			if (i - 2 >= 0 && Map[i - 2][j] != 0)
				temp = max(temp, Map[i - 2][j]);
			if (i + 2 < n && Map[i - 2][j] != 0)
				temp = max(temp, Map[i + 2][j]);
			if (j - 2 >= 0 && Map[i][j - 2] != 0)
				temp = max(temp, Map[i][j - 2]);
			if (j + 2 < m && Map[i][j + 2] != 0)
				temp = max(temp, Map[i][j + 2]);
			res = max(res, temp + Map[i][j]);
		}
	}
	return res;
}
int main()
{

	cin >> n >> m;
	Map.resize(n, vector<int>(m));
	int temp = 0;
	int count = 0;
	for (int i = 0; i < n * m; ++i)
	{
		cin >> temp;
		Map[i / m][i % m] = temp;
		if (temp == 1) count++;
	}
	if (count >(m * n - n) || count > (n * m - m)){
		cout << count << endl;
		return 0;
	}
	cout << MaxSolider() << endl;
	return 0;
}
#endif


#if 0

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0, m = 0;
	vector<pair<int, int>> cv(n);
	int c = 0, v = 0;
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> c >> v;
		cv[i] = pair<int, int>(c, v);
		if (v > 0)
			res += v;
	}
	cout << res << endl;
	return 0;
}
#endif