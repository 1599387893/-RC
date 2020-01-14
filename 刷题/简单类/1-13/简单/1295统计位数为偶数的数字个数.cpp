#if 0
class Solution {
public:
	int findNumbers(vector<int>& nums) {
		int count = 0;
		for (auto i = 0; i < nums.size(); ++i)
		{
			int bit = 0;
			int temp = nums[i];
			while (temp)
			{
				temp /= 10;
				bit++;
			}
			if (bit % 2 == 0)
				count++;
		}
		return count;
	}
};
#endif