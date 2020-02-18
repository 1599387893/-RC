#if 0
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int ret = nums.size() - 1;
		while (--k)
			ret--;
		return nums[ret];
	}
};
#endif

#if 0
class Solution {
public:
	void Adjust(vector<int>& nums, int parent, int pos)
	{
		int child = parent * 2 + 1;
		while (child < nums.size() - pos)
		{
			if (child + 1<nums.size() - pos && nums[child + 1] > nums[child])
				child += 1;
			if (nums[parent] < nums[child])
				swap(nums[parent], nums[child]);
			parent = child;
			child = parent * 2 + 1;
		}
	}
	void MakeHeap(vector<int>& nums)
	{
		for (int i = nums.size() / 2 - 1; i >= 0; --i)
			Adjust(nums, i, 0);
	}
	int findKthLargest(vector<int>& nums, int k) {
		//½¨¶Ñ
		MakeHeap(nums);
		for (int i = 0; i < k; ++i)
		{
			swap(nums[0], nums[nums.size() - 1 - i]);
			//¶ÑÉ¾³ý
			Adjust(nums, 0, i + 1);
		}
		return nums[nums.size() - k];
	}
};
#endif