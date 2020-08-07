class Solution {
public:
	//dp[i] : 表示爬到第i层所需要的最小体力
	int minCostClimbingStairs(vector<int>& cost) {
		if (cost.size() == 0) return 0;
		if (cost.size() == 1) return cost[0];
		if (cost.size() == 2) return cost[0] > cost[1] ? cost[0] : cost[1];
		vector<int> dp(cost);
		dp.resize(cost.size() + 1);
		dp.back() = 0;
		for (int i = 2; i < dp.size(); ++i)
			dp[i] += min(dp[i - 1], dp[i - 2]);
		return dp.back();
	}
};

class Solution {
public:
	//dp[i] : 表示爬到第i层所需要的最小体力
	int minCostClimbingStairs(vector<int>& cost) {
		if (cost.size() == 0) return 0;
		if (cost.size() == 1) return cost[0];
		if (cost.size() == 2) return cost[0] > cost[1] ? cost[0] : cost[1];
		int ppre = cost[0];
		int pre = cost[1];
		int minCost = 0;
		cost.push_back(0);
		for (int i = 2; i < cost.size(); ++i)
		{
			minCost = cost[i] + min(ppre, pre);
			ppre = pre;
			pre = minCost;
		}
		return minCost;
	}
};