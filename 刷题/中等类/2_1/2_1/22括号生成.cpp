//回溯法
#if 0
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		BackTrack(res,"",n,0);//第一个填入的一定是‘(’
		return res;
	}
	void BackTrack(vector<string>& res,string str,int left,int right)
	{
		if(left==0 && right==0)
		{
			res.push_back(str);
			return ;
		}
		if(left > 0)
			BackTrack(res,str+'(',left-1,right+1);//当给结果中加入一个‘(’，就要保证在后边会有一个‘)’与其匹配
		if(right > 0)
			BackTrack(res,str+')',left,right-1);
	}
};
#endif

#if 0
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		BackTrack(res, "", 0, 0, n);
		return res;
	}
	void BackTrack(vector<string>& res, string str, int left, int right, int n)
	{
		if (left == n && right == n)
		{
			res.push_back(str);
			return;
		}
		if (left < n)
			BackTrack(res, str + '(', left + 1, right, n);
		if (right < left)
			BackTrack(res, str + ')', left, right + 1, n);
	}
};
#endif

//暴力求解法+剪枝
#if 0
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		if (n == 0)
			return res;
		if (n == 1)
		{
			res.push_back("()");
			return res;
		}
		string s = "";
		for (int i = 0; i < n; ++i)
			s += "()";
		sort(s.begin(), s.end());
		do{
			if (IsLegal(s))
				res.push_back(s);
		} while (next_permutation(s.begin() + 1, s.end()));
		return res;
	}
	bool IsLegal(string& s)
	{
		int count = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
				count++;
			else
				count--;
			if (count<0)
				return false;
		}
		return true;

	}
};
#endif
