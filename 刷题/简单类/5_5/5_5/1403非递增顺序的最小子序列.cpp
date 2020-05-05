class Solution {
public:
	vector<int> minSubsequence(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> res;
		long left = 0, right = 0;
		for (const auto c : nums)
			left += c;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			left -= nums[i];
			right += nums[i];
			res.push_back(nums[i]);
			if (left < right)
				break;
		}
		return res;
	}
};

class Solution {
public:
	int minStartValue(vector<int>& nums) {
		vector<int> temp;
		partial_sum(nums.begin(), nums.end(), back_inserter(temp));
		int res = *min_element(temp.begin(), temp.end());
		return res >= 1 ? 1 : abs(res) + 1;
	}
};