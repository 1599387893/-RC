class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		vector<int> ROW;
		vector<int> COL(matrix[0].size(), 0);
		for (int i = 0; i < matrix.size(); ++i)
		{
			ROW.push_back(matrix[i][0]);
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				if (ROW[i]>matrix[i][j]) ROW[i] = matrix[i][j];
				if (COL[j]<matrix[i][j]) COL[j] = matrix[i][j];
			}
		}
		vector<int> res;
		for (int i = 0; i < matrix.size(); ++i)
			for (int j = 0; j < matrix[0].size(); ++j)
				if (matrix[i][j] == ROW[i] && matrix[i][j] == COL[j])
					res.push_back(matrix[i][j]);
		return res;
	}
};