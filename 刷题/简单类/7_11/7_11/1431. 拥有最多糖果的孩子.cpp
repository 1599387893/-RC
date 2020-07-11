class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		vector<bool> res(candies.size());
		if (candies.size() == 0) return res;
		int rich = candies[0];
		for (int i = 0; i < candies.size(); ++i)
			rich = max(rich, candies[i]);
		for (int i = 0; i < candies.size(); ++i)
			res[i] = candies[i] + extraCandies >= rich;
		return res;

	}
};