#if 0
class Solution {
public:
	string addBinary(string a, string b) {
		string res;
		bool carry = false; //进位标志
		if (a.size() > b.size())
			a.swap(b);
		int gap = b.size() - a.size();
		for (int i = 0; i < gap; ++i) //将两个字符串长度相等化
			a.insert(0, "0");
		for (int i = a.size()-1; i >= 0; --i)
		{
			if ((a[i] ^ b[i]) == 1) //0 1或者1 0
				res.insert(0, carry == true ? "0" : "1");
			else //0 0 或者 1 1
			{
				res.insert(res.begin(), carry == true ? '1' : '0');
				carry = a[i] == '1' ? true : false;
			}
		}
		if (carry) //加上最终的进位
			res.insert(res.begin(), '1');
		return res;
	}
};
#endif