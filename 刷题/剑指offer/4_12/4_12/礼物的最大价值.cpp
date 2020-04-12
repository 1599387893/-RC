//递归遍历：时间复杂度太大

class Solution {
public:
	int ret;
	void FindMaxGifts(vector<vector<int>>& grid, int x, int y, int sum)
	{
		if (x == grid.size() - 1 && y == grid[0].size() - 1)
		{
			sum += grid[x][y];
			ret = max(sum, ret);
			return;
		}
		sum += grid[x][y];
		if (x + 1<grid.size())
			FindMaxGifts(grid, x + 1, y, sum);
		if (y + 1<grid[0].size())
			FindMaxGifts(grid, x, y + 1, sum);
	}
	int maxValue(vector<vector<int>>& grid) {
		ret = 0;
		FindMaxGifts(grid, 0, 0, 0);
		return ret;
	}
};

//动态规划：使用额外空间
class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		int x = grid.size(), y = grid[0].size();
		vector<vector<int>> temp(x, vector<int>(y, 0));
		temp[0][0] = grid[0][0];
		for (int i = 1; i<x; ++i)
			temp[i][0] = grid[i][0] + temp[i - 1][0];
		for (int i = 1; i<y; ++i)
			temp[0][i] = grid[0][i] + temp[0][i - 1];
		for (int i = 1; i < x; ++i)
			for (int j = 1; j<y; ++j)
				temp[i][j] = max(temp[i - 1][j], temp[i][j - 1]) + grid[i][j];
		return temp[x - 1][y - 1];
	}
};
//动态规划：在原数组上修改