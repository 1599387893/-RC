#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int curr = nums[0];
	int ret = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		curr = max(curr + nums[i],nums[i]);
		ret = max(ret, curr);
	}
	return curr;
}
int maxSubArray(vector<int>& nums) {
	int cur = nums[0];
	int res = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		cur = max(nums[i], cur + nums[i]);
		res = max(res, cur);
	}
	return res;
}
int main()
{
	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
	cout << maxSubArray(nums);
	return 0;
}