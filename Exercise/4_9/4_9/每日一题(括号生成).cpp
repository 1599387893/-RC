class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		BackTrack(res, "", n, 0);
		return res;
	}
	void BackTrack(vector<string>& res, string str, int left, int right)
	{
		if (left == 0 && right == 0)
		{
			res.push_back(str);
			return;
		}
		if (left>0)
			BackTrack(res, str + '(', left - 1, right + 1);//ÿ�μ�һ��'(',Ҫ��֤֮�����')'����˸�֮����Ҫ�������ŵļ�����1
		if (right > 0)
			BackTrack(res, str + ')', left, right - 1);
	}
};