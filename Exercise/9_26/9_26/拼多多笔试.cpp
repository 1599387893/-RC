#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int T = 0, N = 0;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int count = 0;
		vector<vector<int>> board(N, vector<int>(N, 0));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> board[i][j];
				if (board[i][j])
					count++;
			}
		}
		count /= (N / 10);
		if (count == 7)
			cout << 0 << endl;
		else if (count == 17)
			cout << 1 << endl;
		else if (count == 24)
			cout << 2 << endl;
		else if (count == 24)
			cout << 3 << endl;
		else if (count == 24)
			cout << 4 << endl;
		else if (count == 24)
			cout << 5 << endl;
		else if (count == 25)
			cout << 6 << endl;
		else if (count == 22)
			cout << 7 << endl;
		else if (count == 28)
			cout << 8 << endl;
		else if (count == 25)
			cout << 9 << endl;
	}
	return 0;
}


#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int Count(vector<int> arr, int val)
{
	int ret = 0;
	for (auto n : arr)
		if (n == val)
			ret++;
	return ret;
}
int Rfind(vector<int>& arr, int val)
{
	int ret = -1;
	for (int i = arr.size() - 1; i >= 0; --i)
		if (arr[i] == val)
		{
		ret = i;
		break;
		}
	return ret;
}
int GetNumber(vector<vector<int>>& board, int count, int row, const int big)
{
	if (count == 2) // 1£¬4£¬5
	{
		if (big > 1)
			row += big;
		int n = Count(board[row], 1);
		n /= big;
		if (n == 6)
			return 5;
		if (big > 1)
			row += big;
		n = Count(board[row], 1);
		n /= big;
		if (n == 2)
			return 1;
		if (n == 4)
			return 4;
	}
	else //count==4 £º 0£¬2£¬3£¬6£¬8£¬9
	{
		if (big > 1)
			row += big;
		int n = Count(board[row], 1);
		n /= big;
		if (n == 2)
			return 6;
		else if (n == 6)
			return 2;
		if (big > 1)
			row += big;
		n = Count(board[row], 1);
		n /= big;
		if (n == 2)
			return 3;
		if (big > 1)
			row += big;
		n = Count(board[row], 1);
		n /= big;
		if (n == 5)
			return 9;
		if (big > 1)
			row += big;
		auto pos1 = find(board[row].begin(), board[row].end(), 1);
		int m = Rfind(board[row], 0);
		n = pos1 - board[row].begin();
		n /= big;
		m /= big;
		if (m - n > 3)
			return 0;
		return 8;
	}
}
int main()
{
	int T = 0, N = 0;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int row = -1;
		int count = 0;
		vector<vector<int>> board(N, vector<int>(N, 0));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> board[i][j];
				if (row == -1 && board[i][j]) row = i;
			}
		}
		for (int i = 0; i < N; ++i)
			if (board[row][i]) count++;
		count = count / (N / 10);
		if (count == 6)
			cout << 7 << endl;
		else
			cout << GetNumber(board, count, row, N / 10) << endl;
	}
	return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point
{
	int _x;
	int _y;
	Point(int x, int y)
		: _x(x)
		, _y(y)
	{}
};
typedef struct Point Point;

int MinPath;

void FindWay(vector<vector<char>>& way, Point t, int row, int col, int step)
{
	if (row >= (int)way.size() || row < 0 || col >= (int)way[0].size() || col < 0 || step >= MinPath)
		return;
	if (way[row][col] == '1' || (way[row][col] == 'X' && step != 0))
		return;
	if (row == t._x && col == t._y)
	{
		MinPath = min(MinPath, step);
		return;
	}
	way[row][col] = '1';
	FindWay(way, t, row + 1, col, step + 1);
	FindWay(way, t, row - 1, col, step + 1);
	FindWay(way, t, row, col + 1, step + 1);
	FindWay(way, t, row, col - 1, step + 1);
	way[row][col] = '0';
}
int main()
{
	int N = 0, M = 0;
	cin >> N >> M;
	MinPath = M * N;
	vector<vector<char>> way(N, vector<char>(M));
	Point t(0, 0);
	vector<Point> vp;
	for (int i = 0; i < N * M; ++i)
	{
		cin >> way[i / M][i % M];
		if (way[i / M][i % M] == 'T')
		{
			t._x = i / M;
			t._y = i % M;
		}
		else if (way[i / M][i % M] == 'X')
			vp.push_back(Point(i / M, i % M));
	}
	for (auto p : vp)
		FindWay(way, t, p._x, p._y, 0);
	cout << MinPath << endl;
	for (int i = 0; i < (int)vp.size(); ++i)
		if ((abs(vp[i]._x - t._x) + abs(vp[i]._y - t._y)) == MinPath)
			cout << vp[i]._x << " " << vp[i]._y << " ";
	cout << endl;
	return 0;
}
#endif