class Solution {
public:
	void BackTrack(vector<vector<int>>& res, vector<int> temp, const int& k, const int& n, int sum, int pos)
	{
		if (temp.size() == k && sum == n)
			res.push_back(temp);
		if (sum>n || temp.size()>k || pos > n - sum) return;
		for (int i = pos + 1; i <= 9 && temp.size()<k; ++i)
		{
			temp.push_back(i);
			BackTrack(res, temp, k, n, sum + i, i);
			temp.pop_back();
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		if (n>45 || n <= 0) return res;
		for (int i = 1; i <= 9; ++i)
		{
			vector<int> temp;
			temp.push_back(i);
			BackTrack(res, temp, k, n, i, i);
		}
		return res;
	}
};