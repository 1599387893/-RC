#if 0
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		vector<int> temp;
		for (auto n : nums)
			if (n != 0)
				temp.push_back(n);
		temp.resize(nums.size());
		nums = temp;
	}
};

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int pos = 0;
		int cur = 0;
		while (cur < nums.size())
		{
			if (nums[cur] != 0)
			{
				nums[pos++] = nums[cur];
			}
			cur++;
		}
		while (pos < nums.size())
			nums[pos++] = 0;
	}
};
#endif