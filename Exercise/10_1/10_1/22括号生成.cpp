class Solution {
public:
	vector<string> res;
	void BackTrace(string str, int left, int right)
	{
		if (!left && !right)
		{
			res.push_back(str);
			return;
		}
		if (left > 0)
			BackTrace(str + '(', left - 1, right + 1);
		if (right > 0)
			BackTrace(str + ')', left, right - 1);

	}
	vector<string> generateParenthesis(int n) {
		if (n == 0) return res;
		string str;
		BackTrace(str, n, 0);
		return res;
	}
};