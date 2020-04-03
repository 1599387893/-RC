#if 0
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int ret = nums[nums.size() / 2];
		int count = 0;
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] == ret)
				count++;
		if (count > nums.size() / 2)
			return ret;
		return -1;
	}
};
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> m;
		for (int i = 0; i < nums.size(); ++i)
			m[nums[i]]++;
		for (auto it = m.begin(); it != m.end(); ++it)
			if ((*it).second > nums.size() / 2)
				return (*it).first;
		return -1;
	}
};

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int target = nums[0], count = 1;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (target == nums[i])
				count++;
			else
				count--;
			if (count == 0)
			{
				target = nums[i];
				count = 1;
			}
		}
		return target;
	}
};
#endif