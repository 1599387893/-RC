#if 0
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getmoney(std::vector<int>& nums) {
	//¶¯Ì¬¹æ»®
	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0];
	if (nums.size() == 2) return max(nums[0], nums[1]);
	vector<int> dp(nums);
	for (int i = 2; i < nums.size(); ++i)
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	return dp.back();
}


int main() {
	std::vector<int> nums;
	int i = 0;
	char ch = '0';
	while (ch != '\n')
	{
		std::cin >> i;
		nums.push_back(i);
		ch = getchar();
	}
	printf("%d\n", getmoney(nums));
	return 0;
}
#endif