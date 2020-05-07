class Solution {
public:
	int numSpecialEquivGroups(vector<string>& A) {
		unordered_set<string> res;
		for (auto str : A)
		{
			string odd, even;
			for (int i = 0; i < str.size(); ++i)
				i % 2 ? odd.push_back(str[i]) : even.push_back(str[i]);
			sort(odd.begin(), odd.end());
			sort(even.begin(), even.end());
			res.insert(odd + even);
		}
		return res.size();
	}
};