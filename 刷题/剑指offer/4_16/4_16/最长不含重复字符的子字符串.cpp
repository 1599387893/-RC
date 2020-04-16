#if 0
//��������
//1. ��ʼ��ͷβָ�� head��tail��
//2. tail ָ�����ƣ��ж� tail ָ���Ԫ���Ƿ���[head:tail] �Ĵ����ڣ�
//		���������û�и�Ԫ�أ��򽫸�Ԫ�ؼ��봰�ڣ�ͬʱ���´��ڳ������ֵ��tail ָ��������ƣ�
//		��������д��ڸ�Ԫ�أ��� head ָ�����ƣ�ֱ�������в�������Ԫ�ء�

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> um;  //���滬��������ÿ���ַ��Լ�����λ��
		int res = 0, l = 0, r = 0; //����������l��rȷ����
		while (r<s.size())
		{
			//������߽�
			if (um.find(s[r]) != um.end()) //�鿴��ǰԪ���Ƿ��ڻ����������ظ�
				l = max(l, um[s[r]] + 1); //����ظ�����ô��������С��������ͻ���Ǹ�Ԫ�ص���һ��λ�ã�
			//�����ұ߽�
			um[s[r++]] = r; //��um���£�ͬʱ�ұ߽�����(�����ƶ�r��־��ͬʱ����Ԫ�غ�����λ����ӵ�unordered_map��)
			res = max(r - l, res); //��������ظ��Ӵ�
		}
		return res;
	}
};

//��̬�滮
//dp[i]��ʾ�Ե�i���ַ���β�����ظ��ַ��Ӵ����ȣ�
//1. �����i���ַ���֮ǰû�г��ֹ�����ô dp[i]=dp[i-1]+1;
//2. �����i���ַ���֮ǰ���ֹ�����ô�ü�����ַ��ϴγ��ֵ�λ�õ���ǰ�ľ���d��
//	   a.���dС�ڵ���dp[i-1]����˵�����ַ��ϴγ�������i-1λ�ý�β���Ӵ��У���ôdp[i]= d;
//     b.���d����dp[i-1]��˵�����ַ�����������i-1�ַ�Ϊ��β���Ӵ��У���ôdp[i]=dp[i-1]+1;
//3.�ڱ��������У��Ƚϳ�����ظ��ַ��Ӵ�����
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
			return 0;
		if (s.size()<2)
			return 1;
		unordered_map<char, int> um;
		vector<int> dp(s.size());
		um.insert(make_pair(s[0], 0));
		int res = 0;
		dp[0] = 1;
		for (int i = 1; i < s.size(); ++i)
		{
			auto it = um.find(s[i]);
			if (it == um.end())
			{
				dp[i] = dp[i - 1] + 1;
				um.insert(make_pair(s[i], i));
			}
			else
			{
				if ((i - (*it).second) <= dp[i - 1])
					dp[i] = i - (*it).second;
				else
					dp[i] = dp[i - 1] + 1;
				um[s[i]] = i;
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};

#endif