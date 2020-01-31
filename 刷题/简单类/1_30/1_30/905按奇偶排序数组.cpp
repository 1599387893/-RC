#if 0
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		vector<int> res(A.size());
		int begin = 0, end = A.size() - 1;
		for (int i = 0; i < A.size(); ++i)
		{
			if (A[i] % 2 == 0)
				res[begin++] = A[i];
			else
				res[end--] = A[i];
		}
		return res;
	}
};
#endif