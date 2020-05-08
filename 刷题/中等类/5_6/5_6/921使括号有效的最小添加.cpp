class Solution {
public:
	int minAddToMakeValid(string S) {
		int n = 0;
		int res = 0;
		for (auto c : S)
		{
			c == '(' ? n++ : n--;
			if (n<0)
			{
				res++;
				n = 0;
			}
		}
		if (n) res += n;
		return res;
	}
};