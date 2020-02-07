#if 0
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int begin = 0, end = 0;
		bool flag = true;
		vector<int> temp(nums);
		sort(temp.begin(), temp.end());
		for (int i = 0; i <nums.size(); ++i)
		{
			while (i<nums.size() && nums[i] != temp[i])
			{
				if (begin == 0 && flag)
				{
					begin = i;
					flag = false;
				}
				end = i + 1;
				i++;
			}
		}
		return end - begin;

	}
};
#endif