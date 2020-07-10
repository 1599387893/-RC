class Solution {
public:
	int respace(vector<string>& dictionary, string sentence) {
		if (dictionary.size() == 0) return sentence.size();
		if (sentence.size() == 0) return 0;
		vector<int> dp(sentence.size() + 1);
		for (int i = 0; i < sentence.size(); ++i)
		{
			dp[i + 1] = dp[i] + 1;
			for (auto& word : dictionary)
			{
				if ((word.size() <= i + 1) && (word == sentence.substr(i + 1 - word.size(), word.size())))
				{
					dp[i + 1] = min(dp[i + 1], dp[i + 1 - word.size()]);
				}
			}
		}
		return dp[sentence.size()];
	}
};