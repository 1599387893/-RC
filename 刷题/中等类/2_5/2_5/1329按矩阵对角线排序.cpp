#if 0
class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		int Col = mat[0].size();
		int Row = mat.size();
		if (Row == 1 || Row == 0 || Col == 1)
			return mat;
		//左半部分
		for (int i = Row - 2; i >= 0; i--)
		{
			int col = 0;
			vector<int> temp;
			//收集元素
			for (int j = i; j < Row && col < Col; ++j, col++)
				temp.push_back(mat[j][col]);
			//排序
			sort(temp.begin(), temp.end());
			col = 0;
			//排列元素
			for (int j = i; j < Row && col < Col; ++j, col++)
				mat[j][col] = temp[col];
		}
		//右半部分
		for (int i = 1; i <Col - 1; ++i)
		{
			int row = 0;
			vector<int> temp;
			//收集元素
			for (int j = i; j < Col && row < Row; ++j, row++)
				temp.push_back(mat[row][j]);
			//排序
			sort(temp.begin(), temp.end());
			row = 0;
			//排列元素
			for (int j = i; j < Col && row <Row; ++j, row++)
				mat[row][j] = temp[row];
		}
		return mat;
	}
};
#endif