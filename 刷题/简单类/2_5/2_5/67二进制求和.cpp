#if 0
class Solution {
public:
	string addBinary(string a, string b) {
		string res;
		bool carry = false; //��λ��־
		if (a.size() > b.size())
			a.swap(b);
		int gap = b.size() - a.size();
		for (int i = 0; i < gap; ++i) //�������ַ���������Ȼ�
			a.insert(0, "0");
		for (int i = a.size()-1; i >= 0; --i)
		{
			if ((a[i] ^ b[i]) == 1) //0 1����1 0
				res.insert(0, carry == true ? "0" : "1");
			else //0 0 ���� 1 1
			{
				res.insert(res.begin(), carry == true ? '1' : '0');
				carry = a[i] == '1' ? true : false;
			}
		}
		if (carry) //�������յĽ�λ
			res.insert(res.begin(), '1');
		return res;
	}
};
#endif