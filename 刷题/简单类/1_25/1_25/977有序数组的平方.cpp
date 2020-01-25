#if 0
class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		vector<int> res;
		for (int i = 0; i < A.size(); ++i)
			res.push_back(A[i] * A[i]);
		sort(res.begin(), res.end());
		return res;
	}
};
#endif
#if 0
class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		multiset<int> res;
		vector<int> ret;
		for (int i = 0; i < A.size(); ++i)
			res.insert(A[i] * A[i]);
		for (auto it : res)
			ret.push_back(it);
		return ret;
	}
};
#endif