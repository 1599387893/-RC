class Solution {
public:
	string removeDuplicates(string S) {
		int pos = 0;
		while (pos < S.size())
		{
			if (pos + 1 < S.size() && S[pos + 1] == S[pos])
			{
				S.erase(S.begin() + pos + 1);
				S.erase(S.begin() + pos);
				if (pos >= 1) pos--;
			}
			else
				pos++;
		}
		return S;
	}
};

class Solution {
public:
	string removeDuplicates(string S) {
		string res;
		for (auto c : S)
		{
			if (res.empty() || c != res.back())
				res.push_back(c);
			else
				res.pop_back();
		}
		return res;
	}
};