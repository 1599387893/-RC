class WordDictionary {
public:
	/** Initialize your data structure here. */
	bool isEnd;
	vector<WordDictionary*> next;
	WordDictionary() {
		isEnd = false;
		next = vector<WordDictionary*>(26, nullptr);
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		int n = word.length();
		WordDictionary* node = this;
		for (int i = 0; i<n; i++){
			int idx = word[i] - 'a';
			if (node->next[idx] == NULL) node->next[idx] = new WordDictionary();
			node = node->next[idx];
		}
		node->isEnd = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		WordDictionary* cur = this;
		return subSearch(cur, word);
	}
	bool subSearch(WordDictionary* p, string word){
		if (p == NULL) return false;
		int n = word.length();
		for (int i = 0; i<n; i++){
			if (word[i] == '.'){
				for (int j = 0; j<26; j++){
					if (subSearch(p->next[j], word.substr(i + 1))) return true;
				}
				return false;
			}
			int idx = word[i] - 'a';
			if (p->next[idx] == NULL) return false;
			p = p->next[idx];
		}
		return p->isEnd;
	}
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary* obj = new WordDictionary();
* obj->addWord(word);
* bool param_2 = obj->search(word);
*/
