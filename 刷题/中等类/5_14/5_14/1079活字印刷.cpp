#if 0
//使用库函数
class Solution {
public:
	int numTilePossibilities(string tiles) {
		set<string> res;
		sort(tiles.begin(), tiles.end());
		while (1)
		{
			for (int i = 0; i < tiles.size(); ++i)
				res.insert(tiles.substr(0, i + 1));
			if (!next_permutation(tiles.begin(), tiles.end()))
				break;
		}
		return (int)res.size();
	}
};

//回溯法
class Solution {
public:
	int ans;
	int numTilePossibilities(string tiles) {
		vector<int> m(26, 0);
		ans = 0;
		for (auto c : tiles)
			m[c - 'A']++;
		dfs(m);
		return ans;
	}
	void dfs(vector<int>& m)
	{
		for (int i = 0; i <26; ++i)
		{
			if (m[i])
			{
				m[i]--;
				ans++;
				dfs(m);
				m[i]++;
			}
		}
	}
};
#endif