class Solution {
public:
	vector<int> printNumbers(int n) {
		int end = pow(10, n) - 1;
		vector<int> res;
		for (int i = 1; i <= end; ++i)
			res.push_back(i);
		return res;
	}
};