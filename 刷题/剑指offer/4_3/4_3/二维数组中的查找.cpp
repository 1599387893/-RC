#if 0
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;
		int row = 0, col = matrix[0].size() - 1;
		while (row < matrix.size() && col >= 0)
		{
			if (target == matrix[row][col])
				return true;
			else if (target > matrix[row][col])
				row++;
			else
				col--;
		}
		return false;
	}
};
#endif