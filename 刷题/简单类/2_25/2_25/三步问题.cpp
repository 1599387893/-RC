#if 0
class Solution {
public:
	vector<long> step{ 0, 1, 2, 4 };
	int waysToStep(int n) {
		if (n < 4)
			return step[n];
		for (long i = 4; i <= n; ++i)
			step.push_back((step[i - 1] + step[i - 2] + step[i - 3]) % 1000000007);
		return step[n];
	}
};
#endif
