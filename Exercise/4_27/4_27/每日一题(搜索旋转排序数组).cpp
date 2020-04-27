class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;
		int l = 0, r = nums.size() - 1;
		int mid = 0;
		while (l <= r)
		{
			mid = l + (r - l) / 2;
			if (nums[mid] == target) return mid;
			//左边有序
			if (nums[0] <= nums[mid])
			{
				if (target >= nums[0] && target < nums[mid]) // target在区间[0，mid)中；
					r = mid - 1;
				else
					l = mid + 1;
			}
			//右边有序
			else
			{
				if (target >nums[mid] && target <= nums[nums.size() - 1]) //target在区间(mid,nums.size()-1]中
					l = mid + 1;
				else
					r = mid - 1;
			}
		}
		return -1;
	}
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
};


