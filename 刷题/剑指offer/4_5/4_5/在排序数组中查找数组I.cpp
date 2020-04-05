class Solution {
public:
	int search(vector<int>& nums, int target) {
		int res = 0;
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] == target)
				res++;
		return res;
	}
};

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1;
		while (begin < end && nums[begin] != target)
			begin++;
		while (begin < end && nums[end] != target)
			end--;
		return end - begin + 1;
	}
};


class Solution {
public:
	int search(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1;
		while (begin < nums.size() && nums[begin] != target)
			begin++;
		while (end >= 0 && nums[end] != target)
			end--;
		return begin <= end ? end - begin + 1 : 0;
	}
};