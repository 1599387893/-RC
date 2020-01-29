#if 0
class Solution {
public:
	int matrixScore(vector<vector<int>>& A) {
		int count = 0;
		//先翻转行，将每一行的第一个元素转换为1；
		for (int i = 0; i<A.size(); ++i)
			if (A[i][0] != 1)
				for (int j = 0; j<A[i].size(); ++j)
					A[i][j] ^= 1;
		//在反转列，当每一列中值为0的个数大于值为1的个数时，将该行反转；
		for (int i = 1; i < A[0].size(); ++i)
		{
			int zero = 0, one = 0;
			for (int j = 0; j <A.size(); ++j)
			{
				if (A[j][i] == 0)
					zero++;
				else
					one++;
			}
			if (zero>one)
				for (int j = 0; j <A.size(); ++j)
					A[j][i] ^= 1;
		}
		for (int i = 0; i < A.size(); ++i)
			for (int j = 0; j<A[i].size(); ++j)
				if (A[i][j] == 1)
					count += pow(2, A[i].size() - j - 1);
		return count;
	}
};
#endif