class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> res;
		if (numbers.empty()) return res;
		int left = 0, right = numbers.size() - 1;
		while (left < right)
		{
			if (numbers[left] + numbers[right] == target)
			{
				res.push_back(left + 1);
				res.psush_back(right + 1);
				break;
			}
			else if (numbers[left] + numbers[right] < target)
				left++;
			else
				right--;
		}
		return res;
	}
};
