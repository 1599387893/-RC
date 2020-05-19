class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		vector<string> res;
		vector<unordered_map<char, int>> vum(A.size());
		for (int i = 0; i < A.size(); ++i)
			for (auto c : A[i])
				vum[i][c]++;
		for (auto pair : vum[0])
		{
			int n = pair.second;
			for (int i = 1; i < vum.size(); ++i)
				n = min(n, vum[i][pair.first]);
			while (n--) res.push_back(string(1, pair.first));
		}
		return res;
	}
};

class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		//使用二维数组
		vector<string> res;
		vector<vector<int>> temp(A.size(), vector<int>(26, 0));
		for (int i = 0; i < A.size(); ++i)
			for (auto c : A[i])
				temp[i][c - 'a']++;
		for (int i = 0; i<26; ++i)
		{
			int n = temp[0][i];
			for (int j = 1; j < temp.size(); ++j)
				n = min(n, temp[j][i]);
			while (n--) res.push_back(string(1, i + 'a'));
		}
		return res;
	}
};