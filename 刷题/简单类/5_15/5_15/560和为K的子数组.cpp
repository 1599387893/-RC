#if 0
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int res = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			int sum = 0;
			for (int j = i; j >= 0; --j)
			{
				sum += nums[j];
				if (sum == k) res++;
			}
		}
		return res;
	}
};
//前缀和+hash优化
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int res = 0;
		unordered_map<int, int> um;
		um[0] = 1;
		int pre = 0;
		for (auto n : nums)
		{
			pre += n;
			res += um[pre - k];
			um[pre]++;
		}
		return res;
	}
};
#endif