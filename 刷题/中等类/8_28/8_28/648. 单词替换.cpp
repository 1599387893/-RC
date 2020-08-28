struct TrieNode
{
	bool isEnd;
	vector<TrieNode*> next;
	TrieNode()
	{
		isEnd = false;
		next = vector<TrieNode*>(26, nullptr);
	}
};
class Solution {
public:
	TrieNode* root;
	void MakeTrie(const vector<string>& dictionary)
	{
		if (!root)
			root = new TrieNode();
		for (auto word : dictionary)
		{
			TrieNode* cur = root;
			for (auto c : word)
			{
				if (!cur->next[c - 'a'])
					cur->next[c - 'a'] = new TrieNode();
				cur = cur->next[c - 'a'];
			}
			cur->isEnd = true;
		}
	}

	void Replace(string& word)
	{
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); ++i)
		{
			if (!cur->next[word[i] - 'a'])
				return;
			cur = cur->next[word[i] - 'a'];

			if (cur->isEnd)
			{
				word = word.substr(0, i + 1);
				return;
			}
		}
	}
	void WordReplace(string& sentence)
	{
		vector<string> dict;
		//获取每一个单词
		string res = "";
		auto pos = 0;
		string word = "";
		for (int i = 0; i <= sentence.size(); ++i)
		{
			if (sentence[i] == ' ' || i == sentence.size())
			{
				word = sentence.substr(pos, i - pos);
				Replace(word);
				dict.push_back(word);
				pos = i + 1;
			}
		}
		//cout << endl;
		for (int i = 0; i < dict.size() - 1; ++i)
			res += (dict[i] + " ");
		res += dict.back();
		sentence = res;
	}
	string replaceWords(vector<string>& dictionary, string sentence) {
		MakeTrie(dictionary);
		WordReplace(sentence);
		return sentence;
	}
};