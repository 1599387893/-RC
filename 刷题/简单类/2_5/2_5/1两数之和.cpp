#if 0
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
		{
			auto it = find(nums.begin() + i + 1, nums.end(), (target - nums[i]));
			if (it != nums.end())
			{
				res.push_back(i);
				res.push_back(it - nums.begin());
				break;
			}
		}
		return res;
	}
};
#endif