
//�ⷨһ�� �������
class Solution {
public:
	string longestWord(vector<string>& words) {
		unordered_set<string> uset;
		for (auto word : words)
			uset.insert(word);
		string res = "";
		for (auto word : words)
		{
			if (word.size() > res.size() || (word.size() == res.size() && word.compare(res) < 0))
			{
				int i = 1;
				for (; i < word.size(); ++i)
				{
					if (uset.find(word.substr(0, i)) != uset.end())
						continue;
					else
						break;
				}
				if (i == word.size())
					res = word;
			}
		}
		return res;
	}
};



//�ⷨ���� ʹ��Trie��
//ǰ׺���ڵ�
class TrieNode
{
public:
	vector<TrieNode*> ne;
	TrieNode()
	{
		ne = vector<TrieNode*>(26, nullptr);
	}
};
class Solution {
public:
	TrieNode* root;
	string res;

	void add(string& word)
	{
		TrieNode* ccur = root;
		int size = word.size();
		int i = 0;
		for (i = 0; i < size - 1; ++i)
		{
			if (!ccur->ne[word[i] - 'a'])
				return;
			ccur = ccur->ne[word[i] - 'a'];
		}
		ccur->ne[word[i] - 'a'] = new TrieNode();
		if (size > res.size() || (size == res.size() && word < res))
			res = word;
	}

	string longestWord(vector<string>& words) {
		root = new TrieNode();
		sort(words.begin(), words.end());
		for (auto word : words)
			add(word);
		return res;
	}
};