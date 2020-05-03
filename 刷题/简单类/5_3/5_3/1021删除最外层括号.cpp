class Solution {
public:
	string removeOuterParentheses(string S) {
		//�������ŵ��������������ŵĸ���ʱ����ʱ��������ߵ�����
		string res;
		queue<char> q;
		int left = 0, right = 0;
		for (int i = 0; i<S.size(); ++i)
		{
			S[i] == '(' ? left++ : right++;
			q.push(S[i]);
			if (left == right)
			{
				q.pop();
				while (q.size() != 1)
				{
					res.push_back(q.front());
					q.pop();
				}
				q.pop();
			}
		}
		return res;
	}
};


class Solution {
public:
	string removeOuterParentheses(string S) {
		string ans = "";
		int l = 0, mark = 0;
		for (char i : S){
			if (i == '(')    ++l;
			else --l;
			if (l == 0){
				ans.erase(ans.begin() + mark);
				mark = ans.size();
			}
			else{
				ans.push_back(i);
			}
		}
		return ans;
	}
};




