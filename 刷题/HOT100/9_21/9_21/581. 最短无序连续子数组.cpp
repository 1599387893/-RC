#if 0
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> temp(nums);
		sort(nums.begin(), nums.end());
		int begin = -1, end = 0;
		int count = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (temp[i] != nums[i])
			{
				if (begin == -1)
					begin = i;
				else
					end = i;
			}
			else
				count++;
		}
		return count == nums.size() ? 0 : end - begin + 1;
	}
};

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		stack<int> sta;
		int l = nums.size() - 1;
		int r = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			while (!sta.empty() && nums[sta.top()] > nums[i])
			{
				l = min(l, sta.top());
				sta.pop();
			}
			sta.push(i);
		}
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			while (!sta.empty() && nums[sta.top()] < nums[i])
			{
				r = max(r, sta.top());
				sta.pop();
			}
			sta.push(i);
		}
		return (r > l) ? r - l + 1 : 0;
	}
};
#endif