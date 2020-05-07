class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> res;
		vector<int> arr{ 2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3 };
		int n = 0;
		for (auto str : words)
		{
			n = arr[tolower(str[0]) - 'a'];
			int i = 0;
			for (i = 1; i < str.size(); ++i)
				if (arr[tolower(str[i]) - 'a'] != n)
					break;
			if (i == str.size()) res.push_back(str);
		}
		return res;
	}
};