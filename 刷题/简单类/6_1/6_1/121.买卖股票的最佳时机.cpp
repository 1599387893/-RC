class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1) return 0;
		vector<pair<int, int>> temp(prices.size()); //pair.frist表示第i天及之前的最低值，pair.second表示第i天及之后的最高值
		temp[0] = pair<int, int>(prices[0], 0);
		temp[prices.size() - 1] = pair<int, int>(0, prices[prices.size() - 1]);
		for (int i = 1; i < prices.size(); ++i)
			temp[i].first = min(prices[i], temp[i - 1].first);
		for (int i = prices.size() - 2; i >= 0; --i)
			temp[i].second = max(prices[i], temp[i + 1].second);
		int res = 0;
		for (auto p : temp)
			res = max(res, p.second - p.first);
		return res;
	}
};
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 1 || prices.size() == 0) return 0;
		int res = 0;
		int minvalue = prices[0];
		for (int i = 1; i < prices.size(); ++i)
		{
			res = max(res, prices[i] - minvalue);
			minvalue = min(minvalue, prices[i]);
		}
		return res;
	}
};
