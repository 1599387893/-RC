#if 0
class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		int endDay = days[days.size() - 1];
		vector<int> dp(endDay + 1, 0);
		for (auto d : days)
			dp[d] = INT_MAX;//标记d这一天需要旅游
		for (int i = 1; i <= endDay; ++i)
		{
			if (dp[i] == INT_MAX) //需要旅游
			{
				int day = dp[i - 1] + costs[0];
				int week = i>7 ? dp[i - 7] + costs[1] : costs[1];
				// 如果i<7，选择costs[1]，是因为：有可能七天的票价低于一天的票价。
				int month = i>30 ? dp[i - 30] + costs[2] : costs[2];
				// 如果i<30，选择costs[2]，是因为：有可能三十天的票价低于七天的票价。
				dp[i] = min({ day, week, month });
			}
			else //不需要旅游
				dp[i] = dp[i - 1];
		}
		return dp.back();
	}
};
#endif