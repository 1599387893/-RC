class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		if (nums.size() == 1 || nums.size() == 0)
			return nums;
		int begin = 0;
		int end = nums.size() - 1;
		while (begin < end)
		{
			while (begin < end && nums[begin] % 2 != 0)
				begin++;
			while (begin < end && nums[end] % 2 != 1)
				end--;
			if (begin != end)
				swap(nums[begin], nums[end]);
		}
		return nums;
	}
};