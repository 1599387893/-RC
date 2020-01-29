//回溯法
#if 0
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		BackTrack(res, nums, nums.size(), 0);
		return res;
	}
	void BackTrack(vector<vector<int>>& res, vector<int>& nums, const int& size, int level)
	{
		if (level == size)
		{
			res.push_back(nums);
			return;
		}
		for (int i = level; i < size; ++i)
		{
			if (i != level)
				swap(nums[i], nums[level]);
			BackTrack(res, nums, size, level + 1);
			if (i != level)//回溯
				swap(nums[i], nums[level]);
		}
	}
};
#endif


//在原数组的基础上改变元素的位置，构成重新排列的数组，将重新构成的数组保存到结果集中，回溯(回退)到修改之前的状态；
#include<iostream>
#include<vector>
using namespace std;
void BackTrack(vector<vector<int>>& res, vector<int>& nums, const int& size, int level)
{
	if (level == size)
	{
		res.push_back(nums);
		return;
	}
	for (int i = level; i < size; ++i)
	{
		if (i != level)
			swap(nums[i], nums[level]);
		BackTrack(res, nums, size, level + 1);
		if (i != level)
			swap(nums[i], nums[level]);
	}
}
/*
int main()
{
	vector<int> nums{ 1, 2, 3 };
	vector<vector<int>> res;
	BackTrack(res, nums, nums.size(), 0);
	return 0;
}
*/

#if 0
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		do{
			res.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
	}
};
#endif
#include<algorithm>
//库函数方法

#if 0
int main()
{
	vector<int> nums{ 1, 2, 3 };
	do{
		cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;
	} while (next_permutation(nums.begin(), nums.end()));
	return 0;
}
#endif