class Trie {
private:
	bool isEnd;
	vector<Trie*> next;
public:
	/** Initialize your data structure here. */
	Trie() {
		isEnd = false;
		next = vector<Trie*>(26, nullptr);
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie* node = this;
		int size = word.size();
		for (int i = 0; i < size; ++i)
		{
			if (!node->next[word[i] - 'a'])
			{
				node->next[word[i] - 'a'] = new Trie();
			}
			node = node->next[word[i] - 'a'];
		}
		node->isEnd = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Trie* node = this;
		int size = word.size();
		for (int i = 0; i < size; ++i)
		{
			if (!node->next[word[i] - 'a'])
				return false;
			node = node->next[word[i] - 'a'];
		}
		return node->isEnd;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie* node = this;
		int size = prefix.size();
		for (int i = 0; i < size; ++i)
		{
			if (!node->next[prefix[i] - 'a'])
				return false;
			node = node->next[prefix[i] - 'a'];
		}
		return true;
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/