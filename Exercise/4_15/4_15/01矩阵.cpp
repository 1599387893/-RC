//��̬�滮
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		//��̬�滮��dp[i][j]��ʾ��Ԫ�ص����0�ľ���
		//��Ϊ�����֣��ȼ���dp[i][j]Ԫ�ص���ߺ��ϱߵ�0��������룬�ڼ����ұߺ��±ߴ���0���������
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MAX - 2));
		if (matrix.size() == 0)
			return dp;
		int row = matrix.size(), col = matrix[0].size();
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				if (matrix[i][j] == 0)
					dp[i][j] = 0;
		//�ȼ�����ߺ��ϱ�
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
		//�ټ����ұߺ��±�
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