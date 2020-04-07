//�ⷨһ�����ø����ռ�
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
//�ⷨ����ԭ����ת���������ν���������ȷ���ĸ�Ԫ�ص�����λ�ã�
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int row = (n >> 1) - 1; //�ó����Ͽ������е��±�
		int col = (n - 1) >> 1; //�ó����Ͽ������е��±�
		for (int i = row; i >= 0; --i)
			for (int j = col; j >= 0; --j)
			{
				swap(matrix[i][j], matrix[j][n - i - 1]); //ȷ����һ��Ԫ��λ��
				swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);//ȷ���ڶ���Ԫ��λ��
				swap(matrix[i][j], matrix[n - j - 1][i]);//ȷ��������Ԫ��λ��
			}
	}
};
//�ⷨ������ת������ת����ˮƽ��ת�������Խ��߷�ת��
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		//����ˮƽ�ᷭת
		for (int i = 0; i < n / 2; ++i)
			for (int j = 0; j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - i][j]);
		//�������Խ��߷�ת
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < i; ++j)
				swap(matrix[i][j], matrix[j][i]);
	}
};
