
class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		int res = 0;
		int row = matrix.size(), col = matrix[0].size();
		vector<vector<int>> dp(row, vector<int>(col, 0));
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (i == 0 || j == 0)
					dp[i][j] = matrix[i][j];
				else if (matrix[i][j] == 0)
					dp[i][j] = 0;
				else
					dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));;
				res += dp[i][j];
			}
		}
		return res;
	}
};