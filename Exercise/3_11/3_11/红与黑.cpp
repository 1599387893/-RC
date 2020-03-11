// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;
int res = 0;
void CountBlack(vector<vector<char>>& arr, int x, int y)
{
	if (x<0 || x >= (int)arr.size() || y<0 || y >= (int)arr[0].size() || arr[x][y] == '#')//×ß²»Í¨
		return;
	res++;
	arr[x][y] = '#';
	CountBlack(arr, x + 1, y);
	CountBlack(arr, x - 1, y);
	CountBlack(arr, x, y + 1);
	CountBlack(arr, x, y - 1);
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<vector<char>> board(n, vector<char>(m));
		int x, y;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
			cin >> board[i][j];
			if (board[i][j] == '@')
			{
				x = i;
				y = j;
			}
			}
		res = 0;
		CountBlack(board, x, y);
		cout << res << endl;
	}
}