#if 0
class Solution {
public:
	vector<int> sumZero(int n) {
		vector<int> ret(n);
		for (int i = 0; i < n / 2; ++i)
		{
			ret[i] = (i + 1);
			ret[n - i - 1] = -(i + 1);
		}
		return ret;
	}
};
#endif