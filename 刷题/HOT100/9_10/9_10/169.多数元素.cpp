#if 0
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int res = nums[nums.size() / 2];
		int count = 0;
		for (auto n : nums)
			if (res == n)
				count++;
		return count > nums.size() / 2 ? res : 0;
	}
};

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int res = nums[0];
		int count = 1;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (res == nums[i])
				count++;
			else if (count == 1)
				res = nums[i];
			else
				count--;
		}
		return res;
	}
};

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int res = nums[0];
		int count = 1;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (count == 0)
				res = nums[i];
			if (res == nums[i])
				count++;
			else
				count--;
		}
		return res;
	}
};

#endif