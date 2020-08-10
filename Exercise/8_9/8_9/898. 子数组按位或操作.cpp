class Solution {
public:
	int subarrayBitwiseORs(vector<int>& A) {
		unordered_set<int> res;
		for (int i = 0; i < A.size(); ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				int n = 0;
				for (int k = j; k <= i; ++k)
					n |= A[k];
				res.insert(n);
			}
		}
		return res.size();
	}
};