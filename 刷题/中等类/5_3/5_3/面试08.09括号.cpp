#if 0
class Solution {
public:
	vector<string> res;
	vector<string> generateParenthesis(int n) {
		generateParenthesis("", n, 0);//�ڶ���������ʾ����л���Ҫ�������Ÿ�����������������ʾ����л���Ҫ�������Ÿ���
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
			generateParenthesis(s + '(', left - 1, right + 1);//���һ��������(left-1)������Ҫ��֤���ŵ������ԣ����Ժ����ĵݹ��У�һ��Ҫ����һ����������֮ƥ��(right+1)
		if (right>0)
			generateParenthesis(s + ')', left, right - 1);
	}
};
#endif