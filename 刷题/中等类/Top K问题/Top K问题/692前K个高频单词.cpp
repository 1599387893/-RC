#if 0
class Solution {
public:
	struct cmp
	{
		bool operator()(const pair<int, string>& a, const pair<int, string>& b)
		{
			if (a.first != b.first)
				return a.first<b.first;
			else
				return a.second>b.second;
		}
	};
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> mp;
		priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
		vector<string> res;
		vector<int> count;
		for (auto s : words)
			mp[s]++;
		for (auto p : mp)
			pq.push(make_pair(p.second, p.first));
		while (k--)
		{
			res.push_back(pq.top().second);
			pq.pop();
		}
		return res;
	}
};
#endif