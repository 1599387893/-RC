class Solution {
public:
	unordered_map<char, string> num{ { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };
	vector<string> res;
	void Combinat(string& digits, int pos, string str)
	{
		if (pos == digits.size())
		{
			res.push_back(str);
			return;
		}
		for (int i = 0; i < num[digits[pos]].size(); ++i)
			Combinat(digits, pos + 1, str + num[digits[pos]][i]);
	}
	vector<string> letterCombinations(string digits) {
		res.clear();
		if (digits.size() == 0) return vector<string>{};
		Combinat(digits, 0, "");
		return res;
	}
};


//»ØËÝ
class Solution {
public:
	unordered_map<char, string> num{ { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };
	vector<string> res;
	void Combinat(string& digits, int pos, string& str)
	{
		if (pos == digits.size())
		{
			res.push_back(str);
			return;
		}
		for (int i = 0; i < num[digits[pos]].size(); ++i)
		{
			str.push_back(num[digits[pos]][i]);
			Combinat(digits, pos + 1, str);
			str.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		res.clear();
		if (digits.size() == 0) return vector<string>{};
		string str = "";
		Combinat(digits, 0, str);
		return res;
	}
};