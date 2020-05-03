class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//动态规划
		//对于每一个元素，选择是否将他加入数组，或者单独成为新数组，取决于加上后，数组和是否增加。
		int res = INT_MIN, temp = 0;
		for (const auto x : nums)
		{
			temp = max(temp + x, x);
			res = max(res, temp);
		}
		return res;
	}
};