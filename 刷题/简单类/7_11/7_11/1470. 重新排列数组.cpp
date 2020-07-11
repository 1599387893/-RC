class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> res(nums.size());
		int x = 0, y = n;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i % 2 == 0)
				res[i] = nums[x++];
			else
				res[i] = nums[y++];
		}
		return res;
	}
};


class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		if (n == 0) return nums;
		for (int i = 0; i < nums.size(); ++i)
		{
			//ʹ��j��ʾ��ǰ�����Ӧ���ڵ�λ�ã�
			int j = i < n ? i * 2 : 2 * (i - n) + 1;
			nums[j] |= (nums[i] & 1023) << 10;
		}
		for (auto& c : nums)
			c >>= 10;
		return nums;
	}
};