#if 0
class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		int Col = mat[0].size();
		int Row = mat.size();
		if (Row == 1 || Row == 0 || Col == 1)
			return mat;
		//��벿��
		for (int i = Row - 2; i >= 0; i--)
		{
			int col = 0;
			vector<int> temp;
			//�ռ�Ԫ��
			for (int j = i; j < Row && col < Col; ++j, col++)
				temp.push_back(mat[j][col]);
			//����
			sort(temp.begin(), temp.end());
			col = 0;
			//����Ԫ��
			for (int j = i; j < Row && col < Col; ++j, col++)
				mat[j][col] = temp[col];
		}
		//�Ұ벿��
		for (int i = 1; i <Col - 1; ++i)
		{
			int row = 0;
			vector<int> temp;
			//�ռ�Ԫ��
			for (int j = i; j < Col && row < Row; ++j, row++)
				temp.push_back(mat[row][j]);
			//����
			sort(temp.begin(), temp.end());
			row = 0;
			//����Ԫ��
			for (int j = i; j < Col && row <Row; ++j, row++)
				mat[row][j] = temp[row];
		}
		return mat;
	}
};
#endif