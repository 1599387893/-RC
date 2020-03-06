
#if 0
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> res;
		vector<int> temp;
		int sum;
		for (int i = 1; i <= target / 2; ++i)
		{
			sum = 0;
			temp.clear();
			for (int j = i; sum < target; ++j)
			{
				temp.push_back(j);
				sum += j;
			}
			if (sum == target && temp.size()>1)
				res.push_back(temp);
		}
		return res;
	}
};

//»¬¶¯´°¿Ú
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> res;
		if (target < 3)
			return res;
		int left = 1, right = 2;
		int sum = 3;
		vector<int> temp{ 1, 2 };
		while (left < right && right <= target / 2 + 1)
		{
			if (sum<target)
			{
				right++;
				temp.push_back(right);
				sum += right;
			}
			else if (sum > target)
			{
				temp.erase(temp.begin());
				sum -= left;
				left++;
			}
			else
			{
				res.push_back(temp);
				temp.erase(temp.begin());
				sum -= left;
				left++;
			}
		}
		return res;
	}
};
#endif