#if 0
class Solution {
public:
	vector<string> res;
	vector<string> generateParenthesis(int n) {
		generateParenthesis("", n, 0);//第二个参数表示结果中还需要的左括号个数，第三个参数表示结果中还需要的右括号个数
		return res;
	}
	void generateParenthesis(string s, int left, int right)
	{
		if (left == right && left == 0)
		{
			res.push_back(s);
			return ;
		}
		if (left>0)
			generateParenthesis(s + '(', left - 1, right + 1);//添加一个左括号(left-1)，就需要保证括号的完整性，所以后续的递归中，一定要加上一个右括号与之匹配(right+1)
		if (right>0)
			generateParenthesis(s + ')', left, right - 1);
	}
};
#endif