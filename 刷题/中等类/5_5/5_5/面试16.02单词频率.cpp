#if 0
//方法一：使用unordered_map
class WordsFrequency {
public:
	unordered_map<string, int> um;
	WordsFrequency(vector<string>& book) {
		for (auto s : book)
			um[s]++;
	}

	int get(string word) {
		return um[word];
	}
};
#endif