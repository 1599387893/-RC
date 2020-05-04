//问题：给定一个非负整数数组，你最初位于数组的第一个位置。数组中的每个元素代表你在该位置可以跳跃的最大长度。你的目标是使用最少的跳跃次数到达数组的最后一个位置。

//方法一：反向查找出发位置
class Solution {
public:
	//反向查找，贪心算法
	int jump(vector<int>& nums) {
		if (nums.size() <= 1) return 0;
		if (count(nums.begin(), nums.end(), 1) == nums.size())
			return nums.size() - 1;
		int pos = nums.size() - 1; //标记每次的落脚位置，因为是反向找，所以最开始在最后一个元素的位置
		int steps = 0;
		while (pos > 0)
		{
			//从左向右找可以到达下一步落脚点的最远位置，保证他的最小步数。
			for (int i = 0; i < pos; ++i)
			{
				//如果从该位置(i)可以到达(+nums[i])下一步的落脚点(pos),就将该位置作为新的落脚点向前移动。
				if (i + nums[i] >= pos)
				{
					pos = i;
					steps++;
					break;
				}
			}
		}
		return steps;
	}
};


//正向查找可达到的最大位置
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() <= 1) return 0;
		if (count(nums.begin(), nums.end(), 1) == nums.size()) return nums.size() - 1;
		int maxPos = 0, n = nums.size(), step = 0;
		int end = 0; //用来标记在每一步中可以到达的最远距离，如果移动到end位置，说明已经确定这一步可以最远到达end
		for (int i = 0; i < n - 1; ++i) {
			if (maxPos >= i) {
				maxPos = max(maxPos, i + nums[i]);
				if (i == end) {
					end = maxPos;
					++step;
				}
			}
		}
		return step;
	}
};