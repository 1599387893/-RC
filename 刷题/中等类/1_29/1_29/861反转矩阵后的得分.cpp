#if 0
class Solution {
public:
	int matrixScore(vector<vector<int>>& A) {
		int count = 0;
		//�ȷ�ת�У���ÿһ�еĵ�һ��Ԫ��ת��Ϊ1��
		for (int i = 0; i<A.size(); ++i)
			if (A[i][0] != 1)
				for (int j = 0; j<A[i].size(); ++j)
					A[i][j] ^= 1;
		//�ڷ�ת�У���ÿһ����ֵΪ0�ĸ�������ֵΪ1�ĸ���ʱ�������з�ת��
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