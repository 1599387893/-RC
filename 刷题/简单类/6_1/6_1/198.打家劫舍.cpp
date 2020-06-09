class Solution {
public:
	int rob(vector<int>& nums) {
		//动态规划（O(n)）
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		vector<int> temp(nums.size());
		temp[0] = nums[0];
		temp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); ++i)
			temp[i] = max(temp[i - 1], temp[i - 2] + nums[i]);
		return temp[temp.size() - 1];
	}
};
class Solution {
public:
	int rob(vector<int>& nums) {
		//动态规划（O(1)）
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		int frist = nums[0], second = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); ++i)
		{
			int temp = max(second, frist + nums[i]);
			frist = second;
			second = temp;
		}
		return second;
	}
};