class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		vector<int> temp(nums.size(), 0);
		for (auto n : nums)
		{
			temp[n - 1]++;
			if (temp[n - 1]>1) return n;
		}
		return -1;
	}
};
//¿ìÂıÖ¸Õë
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0;
		do
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (fast != slow);
		slow = 0;
		while (fast != slow)
		{
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
};
