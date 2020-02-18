#if 0
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unorderd_map<int, int> mp;
		priority_queue<pair<int, int>> pq;
		for (auto n : nums)
			mp[n]++;
		for (auto m : mp)
			pq.push(make_pair(m.second, m.first));
		vector<int> res;
		for (int i = 0; i < k; ++i)
		{
			res.push_back(pq.top().second);
			pq.pop();
		}
		return res;
	}
};
#endif