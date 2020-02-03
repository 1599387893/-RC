#if 0
class Solution {
public:
	bool IsIndex(vector<int>& nums, int mid)
	{
		int left = 0, right = 0;
		for (int i = 0; i < mid; ++i)
			left += nums[i];
		for (int i = nums.size() - 1; i>mid; --i)
			right += nums[i];
		if (left == right)
			return true;
		return false;
	}
	int pivotIndex(vector<int>& nums) {
		if (nums.size() == 0)
			return -1;
		for (int i = 0; i < nums.size(); ++i)
			if (IsIndex(nums, i))
				return  i;
		return -1;
	}
};
#endif

#if 0
class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		if (nums.size() == 0)
			return -1;
		int right = 0, left = 0;
		for (int i = 0; i < nums.size(); ++i)
			right += nums[i];
		for (int i = 0; i< nums.size(); ++i)
		{
			right -= nums[i];
			if (left == right)
				return i;
			left += nums[i];
		}
		return -1;
	}
};
#endif