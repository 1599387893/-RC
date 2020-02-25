#if 0
class Solution {
public:
	int ROW, COL;
	vector<vector<int>> res;
	bool BackTrack(vector<vector<int>>& obstacleGrid, int row, int col)
	{
		if (row > ROW - 1 || col > COL - 1)
			return false;
		res.push_back(vector<int>{row, col});
		if (row == ROW - 1 && col == COL - 1)
			return true;
		if (obstacleGrid[row][col] == 1)
		{
			res.pop_back();
			return false;
		}
		bool ret;
		if (BackTrack(obstacleGrid, row, col + 1))
			return true;
		ret = BackTrack(obstacleGrid, row + 1, col);
		if (!ret)
			res.pop_back();
		return ret;
	}
	vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1)
			return res;
		ROW = obstacleGrid.size();
		COL = obstacleGrid[0].size();
		BackTrack(obstacleGrid, 0, 0);
		return res;
	}
};
#endif