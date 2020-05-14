#if 0
class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector<int> res;
		unordered_map<char, int> um;
		int start = 0, end = 0;
		for (int i = 0; i < S.size(); ++i)
			um[S[i]] = i;
		for (int i = 0; i < S.size(); ++i)
		{
			end = max(end, um[S[i]]);
			if (i == end)
			{
				res.push_back(end - start + 1);
				start = end + 1;
			}
		}
		return res;
	}
};
#endif