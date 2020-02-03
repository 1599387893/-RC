#if 0
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		for (auto c : nums)
			if (count(nums.begin(), nums.end(), c)>1)
				return true;
		return false;
	}
};
#endif

#if 0
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
			return false;
		sort(nums.begin(), nums.end());
		for (size_t i = 0; i < nums.size() - 1; ++i)
			if (nums[i] == nums[i + 1])
				return true;
		return false;
	}
};
#endif

#if 0
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set s(nums.begin(), nums.end());
		return s.size() == nums.size();
	}
};
#endif