//动态规划
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		//动态规划：dp[i][j]表示该元素到最近0的距离
		//分为两部分，先计算dp[i][j]元素的左边和上边到0的最近距离，在计算右边和下边搭配0的最近距离
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MAX - 2));
		if (matrix.size() == 0)
			return dp;
		int row = matrix.size(), col = matrix[0].size();
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				if (matrix[i][j] == 0)
					dp[i][j] = 0;
		//先计算左边和上边
		for (int i = 0; i<row; ++i)
		{
			for (int j = 0; j<col; ++j)
			{
				if (i - 1 >= 0 && matrix[i][j] == 1)
					dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
				if (j - 1 >= 0 && matrix[i][j] == 1)
					dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
			}
		}
		//再计算右边和下边
		for (int i = row - 1; i >= 0; --i)
		{
			for (int j = col - 1; j >= 0; --j)
			{
				if (i + 1<row && matrix[i][j] == 1)
					dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);
				if (j + 1<col && matrix[i][j] == 1)
					dp[i][j] = min(dp[i][j], 1 + dp[i][j + 1]);
			}
		}
		return dp;
	}
};
//DFS