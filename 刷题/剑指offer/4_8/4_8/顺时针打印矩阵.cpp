#if 0
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty())  return res;
		int left = 0, right = matrix[0].size() - 1;
		int top = 0, down = matrix.size() - 1;
		int i = top, j = left;
		while (top <= down && left <= right)
		{
			//������
			for (j = left; j <= right && top <= down; ++j)
				res.push_back(matrix[i][j]);
			top++;
			j--;
			//������
			for (i = top; i <= down && left <= right; ++i)
				res.push_back(matrix[i][j]);
			right--;
			i--;
			//������
			for (j = right; j >= left && top <= down; --j)
				res.push_back(matrix[i][j]);
			down--;
			j++;
			//������
			for (i = down; i >= top && left <= right; --i)
				res.push_back(matrix[i][j]);
			left++;
			i++;
		}
		return res;
	}
};
#endif