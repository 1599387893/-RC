class Solution {
public:
	string generateTheString(int n) {
		string res;
		if (n % 2) res = string(n, 'a');
		else
		{
			res = string(n - 1, 'a');
			res.push_back('b');
		}
		return res;
	}
};