class Solution {
public:
	vector<int> processQueries(vector<int>& queries, int m) {
		vector<int> p(m);
		vector<int> res;
		for (int i = 0; i < m; ++i)
			p[i] = i + 1;
		for (const auto c : queries)
		{
			auto pos = find(p.begin(), p.end(), c);
			res.push_back(pos - p.begin());
			p.erase(pos);
			p.insert(p.begin(), c);
		}
		return res;
	}
};