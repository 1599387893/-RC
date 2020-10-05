class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		vector<vector<int>> temp(matrix);
		int y = temp.size() - 1;
		for (int row = 0; row < temp.size(); ++row)
		{
			for (int col = 0; col < temp[row].size(); ++col)
				matrix[col][y] = temp[row][col];
			y--;
		}
	}
};

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int size = matrix.size();
		int n = 0;
		for (int i = 0; i < (size + 1) / 2; ++i)
		{
			for (int j = 0; j < size / 2; ++j)
			{
				n = matrix[i][j];
				swap(n, matrix[j][size - i - 1]);
				swap(n, matrix[size - 1 - i][size - 1 - j]);
				swap(n, matrix[size - 1 - j][i]);
				swap(n, matrix[i][j]);
			}
		}
	}
};