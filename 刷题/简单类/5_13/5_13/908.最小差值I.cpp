#if 0
class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		int Max = A[0], Min = A[0];
		for (auto n : A)
		{
			Max = max(Max, n);
			Min = min(Min, n);
		}
		return max(0, Max - Min - 2 * K);
	}
};
#endif