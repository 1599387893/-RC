class Solution {
public:
	string reverseWords(string s) {
		int k = 0;
		for (int i = 0; i < s.size(); ++i){
			while (i < s.size() && s[i] == ' ') ++i;  //找到第一个非空格字符
			if (i == s.size()) break;
			int j = i;
			while (j < s.size() && s[j] != ' ') ++j;    //遍历1个非空单词
			reverse(s.begin() + i, s.begin() + j);      //反转1个单词
			if (k) s[k++] = ' ';
			while (i < j) s[k++] = s[i++];      //反转后的1个单词赋给s[k]
		}
		s.erase(s.begin() + k, s.end());   //删除 k后面空格
		reverse(s.begin(), s.end());
		return s;
	}
};