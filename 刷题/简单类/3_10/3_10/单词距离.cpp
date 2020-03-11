#if 0
class Solution {
public:
	int findClosest(vector<string>& words, string word1, string word2) {
		if (words.size() == 0 || word1 == word2)
			return 0;
		vector<int> pos1, pos2;
		//遍历一次words得到word1和word2的位置信息
		for (int i = 0; i < words.size(); ++i)
		{
			if (words[i] == word1)
				pos1.push_back(i);
			if (words[i] == word2)
				pos2.push_back(i);
			if (words[i] == word1 && words[i] == word2)
				return 0;
		}
		//通过判断两个单词的位置得出最短距离；
		int res = words.size();
		for (int i = 0; i < pos1.size(); ++i)
			for (int j = 0; j<pos2.size(); ++j)
				res = min(res, abs(pos1[i] - pos2[j]));

		return res;

	}
};
#endif

//方法二
#if 0
class Solution {
public:
	int findClosest(vector<string>& words, string word1, string word2) {
		if (words.size() == 0 || word1 == word2)
			return 0;
		vector<int> pos(words.size(), 0);
		//遍历一次words得到word1和word2的位置信息()
		for (int i = 0; i < words.size(); ++i)
		{
			if (words[i] == word1) pos[i] = 1;
			if (words[i] == word2) pos[i] = 2;
		}
		//通过判断两个单词的位置得出最短距离；
		int res = words.size();
		int one = words.size() + 1, two = words.size() + 1;
		for (int i = 0; i < pos.size(); ++i)
		{
			if (pos[i] == 1) one = i;
			if (pos[i] == 2) two = i;
			if (one != words.size() + 1 && two != words.size() + 1)
				res = min(res, abs(one - two));
		}
		return res;

	}
};
#endif