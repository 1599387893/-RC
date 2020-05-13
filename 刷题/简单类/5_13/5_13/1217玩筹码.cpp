#if 0
class Solution {
public:
	int minCostToMoveChips(vector<int>& chips) {
		int odd = 0, even = 0;
		for (auto n : chips)
			n % 2 ? odd++ : even++;
		return min(odd, even);
	}
};
#endif