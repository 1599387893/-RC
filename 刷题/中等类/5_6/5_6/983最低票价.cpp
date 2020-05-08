#if 0
class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		int endDay = days[days.size() - 1];
		vector<int> dp(endDay + 1, 0);
		for (auto d : days)
			dp[d] = INT_MAX;//���d��һ����Ҫ����
		for (int i = 1; i <= endDay; ++i)
		{
			if (dp[i] == INT_MAX) //��Ҫ����
			{
				int day = dp[i - 1] + costs[0];
				int week = i>7 ? dp[i - 7] + costs[1] : costs[1];
				// ���i<7��ѡ��costs[1]������Ϊ���п��������Ʊ�۵���һ���Ʊ�ۡ�
				int month = i>30 ? dp[i - 30] + costs[2] : costs[2];
				// ���i<30��ѡ��costs[2]������Ϊ���п�����ʮ���Ʊ�۵��������Ʊ�ۡ�
				dp[i] = min({ day, week, month });
			}
			else //����Ҫ����
				dp[i] = dp[i - 1];
		}
		return dp.back();
	}
};
#endif