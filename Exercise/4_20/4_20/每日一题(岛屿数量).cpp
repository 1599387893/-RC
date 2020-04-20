#if 0
class Solution {
public:
	void dfs(vector<vector<char>>& grid, int row, int col)
	{
		if (row < grid.size() && col < grid[0].size())
			grid[row][col] = '0';
		if (row + 1 < grid.size() && grid[row + 1][col] == '1') dfs(grid, row + 1, col);
		if (row - 1 >= 0 && grid[row - 1][col] == '1') dfs(grid, row - 1, col);
		if (col + 1 < grid[0].size() && grid[row][col + 1] == '1') dfs(grid, row, col + 1);
		if (col - 1 >= 0 && grid[row][col - 1] == '1') dfs(grid, row, col - 1);
	}
	int numIslands(vector<vector<char>>& grid) {
		//深度优先遍历
		if (grid.size() == 0 || grid[0].size() == 0) return 0;
		int row = grid.size();
		int col = grid[0].size();
		int isLand = 0;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (grid[i][j] == '1')
				{
					isLand++;
					dfs(grid, i, j);
				}
			}
		}
		return isLand;
	}
};
#endif

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		//广度优先
		if (grid.size() == 0 || grid[0].size() == 0)
			return 0;
		int row = grid.size();
		int col = grid[0].size();
		queue<pair<int, int>> q;
		int isLand = 0;
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				if (grid[i][j] == '1')
				{
			isLand++;
			grid[i][j] = '0';
			q.push(make_pair(i, j));
			while (!q.empty())
			{
				pair<int, int> p = q.front();
				q.pop();
				if (p.second + 1<col && grid[p.first][p.second + 1] == '1')
				{
					q.push(make_pair(p.first, p.second + 1));
					grid[p.first][p.second + 1] = '0';
				}
				if (p.second - 1 >= 0 && grid[p.first][p.second - 1] == '1')
				{
					q.push(make_pair(p.first, p.second - 1));
					grid[p.first][p.second - 1] = '0';
				}
				if (p.first + 1<row && grid[p.first + 1][p.second] == '1')
				{
					q.push(make_pair(p.first + 1, p.second));
					grid[p.first + 1][p.second] = '0';
				}
				if (p.first - 1 >= 0 && grid[p.first - 1][p.second] == '1')
				{
					q.push(make_pair(p.first - 1, p.second));
					grid[p.first - 1][p.second] = '0';
				}
			}
				}
		return isLand;
	}
};