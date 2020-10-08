#if 0
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		int n = T.size();
		vector<int> ans(n);
		vector<int> nextMin(101, INT_MAX);
		for (int i = n - 1; i >= 0; --i)
		{
			int MinPos = INT_MAX;
			for (int j = T[i] + 1; j < 101; ++j)
				MinPos = min(MinPos, nextMin[j]);
			if (MinPos == INT_MAX)
				ans[i] = 0;
			else
				ans[i] = MinPos - i;
			nextMin[T[i]] = i;
		}
		return ans;
	}
};



class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> res(T.size());
		stack<int> sta; //��������ջ
		for (int i = 0; i < T.size(); ++i)
		{
			//T[sta.top()] < T[i] ˵��iλ�õ�Ԫ�ر�sta.top()λ�õ�Ԫ�ش󣬲��ң�sta.top()�Ǿ���i����Ĵ�������Ԫ��
			while (!sta.empty() && T[sta.top()] < T[i])
			{
				res[sta.top()] = i - sta.top();
				sta.pop();
			}
			sta.push(i);
		}
		return res;
	}
};

#endif 


