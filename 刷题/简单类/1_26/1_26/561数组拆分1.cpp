#if 0
class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int count = 0;
		for (int i = nums.size() - 2; i >= 0; i -= 2)
			count += nums[i];
		return count;
	}
};
#endif
