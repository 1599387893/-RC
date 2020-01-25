#if 0
class Solution {
public:
	vector<int> diStringMatch(string S) {
		vector<int> res;
		int begin = 0, end = S.size();
		for (int i = 0; i <S.size(); ++i)
		{
			if (S[i] == 'I')
				res.push_back(begin++);
			else
				res.push_back(end--);
		}
		res.push_back(end);
		return res;
	}
};
#endif