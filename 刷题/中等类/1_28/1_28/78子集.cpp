//二进制法
/*
思路：使用二进制来表示子集中元素是原集合的那几个元素，比如：0101(表示该子集包含第一个和第二个元素)；
*/
#if 0
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		res.push_back({});
		int size = nums.size();
		int subsize = pow(2, size);
		int hash = 1;
		while (hash<subsize)
		{
			vector<int> temp;
			for (int k = 0; k < size; ++k)
			{
				int a = 1 << k;
				if (a&hash)
					temp.push_back(nums[k]);
			}
			res.push_back(temp);
			hash++;
		}
		return res;
	}
};
#endif

#if 0
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		res.push_back({});
		for (int i = 0; i < nums.size(); ++i)
		{
			int n = res.size();
			for (int j = 0; j < n; ++j)
			{
				vector<int> temp = res[j];
				temp.push_back(nums[i]);
				res.push_back(temp);
			}
		}
		return res;
	}
};
#endif