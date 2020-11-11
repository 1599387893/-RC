//使用库函数
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		next_permutation(nums.begin(), nums.end());
	}
};

//非库函数
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//首先通过遍历找到非降序的元素对的位置
		int pos = nums.size() - 2;
		while (pos >= 0 && nums[pos] >= nums[pos + 1])
			pos--;

		//判断是否为整体降序，如果是，则将序列反转为整体升序
		if (pos < 0)
		{
			reverse(nums.begin(), nums.end());
			return;
		}

		//以pos为起点，从后向前找第一个比nums[pos]大的元素进行交换；交换完成后，将pos之后的所有元素进行反转(因为本身pos到nums.end这段序列就是接近降序的)
		for (int i = nums.size() - 1; i > pos; --i)
		{
			if (nums[i] > nums[pos])
			{
				swap(nums[i], nums[pos]);
				reverse(nums.begin() + pos + 1, nums.end());
				return;
			}
		}
	}
};




class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//首先通过遍历找到非降序的元素对的位置
		int i = nums.size() - 2;
		while (i >= 0 && nums[i] >= nums[i + 1])
			i--;

		if (i >= 0)
		{
			int j = nums.size() - 1;
			while (j > i && nums[j] <= nums[i])
				j--;
			swap(nums[i], nums[j]);
		}
		reverse(nums.begin() + i + 1, nums.end());
	}
};