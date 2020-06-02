
class Solution {
public:
	string convertToTitle(int n) {
		//十进制转二十六进制
		string res;
		while (n>0)
		{
			n -= 1;
			res.insert(res.begin(), 'A' + n % 26);
			n /= 26;
		}
		return res;
	}
};
