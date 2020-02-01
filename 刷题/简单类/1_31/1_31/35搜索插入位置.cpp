#if 0
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty())
			return 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] == target)
				return i;
			if (nums[i]<target)
				continue;
			else
				return i;
		}
		return nums.size();
	}
};
#endif

#if 0
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty())
			return 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == target)
				return i;
			else if (nums[i]>target)
				return i;
		}
		return nums.size();
	}
};
#endif

#if 0
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty())
			return 0;
		if (nums[0]>target)
			return 0;
		if (nums[nums.size() - 1]<target)
			return nums.size();
		int begin = 0, end = nums.size();
		int mid = 0;
		while (begin < end)
		{
			mid = begin + (end - begin) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid]>target)
				end = mid;
			else
				begin = mid + 1;
		}
		return begin;
	}
};
#endif

#if 0
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty())
			return 0;
		if (nums[0]>target)
			return 0;
		if (nums[nums.size() - 1]<target)
			return nums.size();
		int begin = 0, end = nums.size() - 1;
		int mid = 0;
		while (begin <= end)
		{
			mid = begin + (end - begin) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid]>target)
				end = mid - 1;
			else
				begin = mid + 1;
		}
		return begin;
	}
};
#endif