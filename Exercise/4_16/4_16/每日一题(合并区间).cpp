class Solution {
public:
	struct compare{
		bool operator()(vector<int>& arr1, vector<int>& arr2)
		{
			return arr1[0]<arr2[0];
		}
	}com;
	static bool mycompare(vector<int>& arr1, vector<int>& arr2)
	{
		return arr1[0]<arr2[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;
		if (intervals.empty())
			return res;
		sort(intervals.begin(), intervals.end());
		vector<int> temp = intervals[0];
		for (int i = 1; i<intervals.size(); ++i)
		{
			if (temp[1] >= intervals[i][0])
			{
				if (temp[1] <= intervals[i][1])
					temp[1] = intervals[i][1];
			}
			else
			{
				res.push_back(temp);
				temp = intervals[i];
			}
		}
		res.push_back(temp);
		return res;
	}
};