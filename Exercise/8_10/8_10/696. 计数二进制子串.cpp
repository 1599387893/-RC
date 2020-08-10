#if 0
//ע�⣺ �Ӵ����Գ�����ͬ��


//ͳ��������1��0�ĸ��������ڵĸ�������Сֵ�������������Ӵ�����
class Solution {
public:
	int countBinarySubstrings(string s) {
		int res = 0;
		vector<int> temp(s.size(), 1);
		vector<int> SameChar;
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] == s[i - 1])
				temp[i] = temp[i - 1] + 1;
			else
				SameChar.push_back(temp[i - 1]);
		}
		SameChar.push_back(temp[temp.size() - 1]);
		for (int i = 1; i < SameChar.size(); ++i)
			res += min(SameChar[i], SameChar[i - 1]);
		return res;
	}
};
class Solution {
public:
	int countBinarySubstrings(string s) {
		int res = 0;
		vector<int> SameChar{ 1 };
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] == s[i - 1])
				SameChar.back()++;
			else
				SameChar.push_back(1);
		}
		for (int i = 1; i < SameChar.size(); ++i)
			res += min(SameChar[i], SameChar[i - 1]);
		return res;
	}
};

//��last����֮ǰ��ͬԪ�صĸ�����ʹ��curr������֮ǰԪ�ز�ͬ��Ԫ�ظ���
//����ǰԪ�صĸ���С��֮ǰԪ�صĸ���ʱ��++res
class Solution {
public:
	int countBinarySubstrings(string s) {
		int res = 0;
		int curr = 0, last = 0;
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] == s[i - 1]) curr++;
			else last = curr, curr = 0;
			if (last >= curr) res++;
		}
		return res;
	}
};
#endif