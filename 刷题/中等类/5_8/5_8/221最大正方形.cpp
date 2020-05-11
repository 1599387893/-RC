class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		//动态规划dp[i][j]：表示以第i行第j列为右下角的正方形矩阵的边长大小；
		int res = 0;
		if (matrix.empty()) return 0;
		int row = matrix.size(), col = matrix[0].size();
		vector<vector<int>> dp(row, vector<int>(col, 0));
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (matrix[i][j] == '0')
					continue;
				if (matrix[i][j] == '1')
					dp[i][j] = 1;
				if (i>0 && dp[i - 1][j] && j>0 && dp[i][j - 1])
					dp[i][j] += min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
				res = max(res, dp[i][j]);
			}
		}
		return res*res;
	}
};