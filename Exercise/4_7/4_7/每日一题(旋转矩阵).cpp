//解法一：借用辅助空间
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		vector<vector<int>> temp(matrix.size(), vector<int>(matrix.size()));
		for (int i = 0; i < matrix.size(); ++i)
		{
			int y = matrix.size() - 1 - i;
			for (int j = 0; j < matrix.size(); ++j)
				temp[j][y] = matrix[i][j];
		}
		matrix = temp;
	}
};
//解法二：原地旋转（进行三次交换，可以确定四个元素的最终位置）
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int row = (n >> 1) - 1; //得出左上块的最大行的下标
		int col = (n - 1) >> 1; //得出左上块的最大列的下标
		for (int i = row; i >= 0; --i)
			for (int j = col; j >= 0; --j)
			{
				swap(matrix[i][j], matrix[j][n - i - 1]); //确定第一个元素位置
				swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);//确定第二个元素位置
				swap(matrix[i][j], matrix[n - j - 1][i]);//确定第三个元素位置
			}
	}
};
//解法三：翻转代替旋转（先水平翻转，在主对角线翻转）
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		//按照水平轴翻转
		for (int i = 0; i < n / 2; ++i)
			for (int j = 0; j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - i][j]);
		//按照主对角线翻转
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < i; ++j)
				swap(matrix[i][j], matrix[j][i]);
	}
};
