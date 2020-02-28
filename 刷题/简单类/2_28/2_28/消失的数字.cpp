#if 0
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int temp = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			temp ^= i;
			temp ^= nums[i];
		}
		return temp ^= nums.size();
	}
};
#endif

#if 0
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		for(int i = 0;i < nums.end();++i)
			if(nums[i]!=i)
				return i;
		return nums.size();
	}
};
#endif

#if 0
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sum = 0;
		for (const auto n : nums)
			sum += n;
		return ((nums.size() * (1 + nums.size())) / 2) - sum;
	}
};
#endif