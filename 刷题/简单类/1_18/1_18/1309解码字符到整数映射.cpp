#if 0
class Solution {
public:
	string freqAlphabets(string s) {
		string ret;
		for (int i = s.size() - 1; i >= 0; --i)
		{
			//����ƽ������������ַ����һ����ĸ
			if (s[i] == '#')
			{
				ret += (s[i - 1] - '0' + (s[i - 2] - '0') * 10) + 96;
				i -= 2;
			}

			//��ʾ��a��-��i��
			else
			{
				ret += s[i] - '0' + 96;
			}
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
#endif