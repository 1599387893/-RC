class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res(2, 0);
		int i = 0, j = nums.size() - 1;
		int sum;
		while (i < j)
		{
			sum = nums[i] + nums[j];
			if (target == sum)
			{
				res[0] = nums[i];
				res[1] = nums[j];
				break;
			}
			else if (sum > target)
				j--;
			else
				i++;
		}
		return res;
	}
};