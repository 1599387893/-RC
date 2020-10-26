class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		if (strs.size() == 0)
			return res;
		vector<string> temp(strs);
		for (auto& str : temp)
			sort(str.begin(), str.end());
		unordered_map<string, int> um;
		for (int i = 0; i < temp.size(); ++i)
		{
			if (um.find(temp[i]) == um.end())
			{
				res.push_back(vector<string>{strs[i]});
				um[temp[i]] = (int)res.size() - 1;
			}
			else
				res[um[temp[i]]].push_back(strs[i]);
		}
		return res;
	}
};


class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<double, vector<string>> um;
		vector<vector<string>> res;
		double a[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
		double n;
		for (auto str : strs)
		{
			n = 1;
			for (auto c : str)
				n *= a[c - 'a'];
			um[n].push_back(str);
		}
		for (auto n : um)
			res.push_back(n.second);
		return res;
	}
};
