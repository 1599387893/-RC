#if 0
//方法
一：库函数
class Solution {
public:
	vector<string> permutation(string S) {
		vector<string> res;
		sort(S.begin(), S.end());
		do
		{
			res.push_back(S);
		} while (next_permutation(S.begin(), S.end()));
		return res;
	}
};

//方法二：dfs
class Solution {
public:
	vector<string> res;
	vector<string> permutation(string S) {
		Permutation(S, 0);
		return res;
	}
	void Permutation(string& s, int pos)
		if (pos == s.size()) res.push_back(	{
s);
		for (int i = pos; i<s.size(); ++i)
		{
			swap(s[pos], s[i]);
			Permutation(s, pos + 1);
			swap(s[pos], s[i]);
		}
	}
};
#endif