#if 0
//注意： 子串可以出现相同的


//统计连续的1和0的个数，相邻的个数的最小值是满足条件的子串个数
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

//用last保存之前相同元素的个数，使用curr保存与之前元素不同的元素个数
//当当前元素的个数小于之前元素的个数时，++res
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