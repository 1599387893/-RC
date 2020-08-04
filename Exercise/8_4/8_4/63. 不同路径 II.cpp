class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
		vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 1));
		for (int i = 1; i < obstacleGrid[0].size(); ++i)
			if (obstacleGrid[0][i] == 1 || dp[0][i - 1] == 0)
				dp[0][i] = 0;
		for (int i = 1; i < obstacleGrid.size(); ++i)
			if (obstacleGrid[i][0] == 1 || dp[i - 1][0] == 0)
				dp[i][0] = 0;
		for (int i = 1; i < obstacleGrid.size(); ++i)
		{
			for (int j = 1; j < obstacleGrid[i].size(); ++j)
			{
				if (obstacleGrid[i][j] == 1)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp.back().back();
	}
};


class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
		vector<int> dp(obstacleGrid.size(), 1);
		bool co = true;
		for (int i = 1; i < obstacleGrid[0].size(); ++i)
		{
			if (obstacleGrid[0][i] == 1 || !co)
			{
				dp[i] = 0;
				co = false;
			}
		}
		co = true;
		for (int i = 1; i < obstacleGrid.size(); ++i)
		{
			if (obstacleGrid[i][0] == 1 || !co)
			{
				dp[0] = 0;
				co = false;
			}
			for (int j = 1; j < obstacleGrid[i].size(); ++j)
			{
				if (obstacleGrid[i][j] == 1)
					dp[i] = 0;
				else
					dp[i] += dp[i - 1];
			}
		}
		return dp.back();
	}
};

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
		vector <int> f(m);

		f[0] = (obstacleGrid[0][0] == 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (obstacleGrid[i][j] == 1) {
					f[j] = 0;
					continue;
				}
				if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
					f[j] += f[j - 1];
				}
			}
		}

		return f.back();
	}
};
