class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> um;
		for (int i = 0; i < nums.size(); ++i)
			um[nums[i]] = i + 1;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (um[target - nums[i]] != 0 && um[target - nums[i]] != i + 1)
			{
				res.push_back(i);
				res.push_back(um[target - nums[i]] - 1);
				break;
			}
		}
		return res;

	}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> um;
		vector<int> res(2, -1);
		for (int i = 0; i < nums.size(); ++i)
		{
			if (um.count(target - nums[i]) > 0)
			{
				res[0] = um[target - nums[i]];
				res[1] = i;
				break;
			}
			um[nums[i]] = i;
		}
		return res;
	}
};