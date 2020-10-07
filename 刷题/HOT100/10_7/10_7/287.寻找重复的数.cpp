class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int res = 0;
		unordered_map<int, int> um;
		for (auto n : nums)
		{
			um[n]++;
			if (um[n] > 1)
			{
				res = n;
				break;
			}
		}
		return res;
	}
};


class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int fast = 0, slow = 0;
		do
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (fast != slow);
		slow = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
};