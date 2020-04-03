#if 0
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		vector<int> temp(nums.size(), 0);
		int ret = nums[0];
		for (int i = 0; i <nums.size(); ++i)
		{
			temp[nums[i]]++;
			if (temp[nums[i]] != 1)
			{
				ret = nums[i];
				break;
			}
		}
		return ret;
	}
};


class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int ret;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != i && nums[nums[i]] == nums[i])
			{
				ret = nums[i];
				break;
			}
			if (nums[i] != i && nums[nums[i]] != nums[i])
				swap(nums[i], nums[nums[i]]);
		}
		return ret;
	}
};
#endif