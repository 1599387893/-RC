class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		int COL = A.size(), ROW = A[0].size();
		vector<vector<int>> res(ROW, vector<int>(COL));
		int col = 0, row = 0;
		for (int i = 0; i < COL; ++i, col++)
			for (int j = 0; j < ROW; ++j, row++)
				res[row%ROW][col] = A[i][j];
		return res;
	}
};

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		int COL = A.size(), ROW = A[0].size();
		vector<vector<int>> res(ROW, vector<int>(COL));
		for (int i = 0; i < COL; ++i)
			for (int j = 0; j < ROW; ++j)
				res[j][i] = A[i][j];
		return res;
	}
};