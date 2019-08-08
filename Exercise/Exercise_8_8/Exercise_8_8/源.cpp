#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
	if (s.empty() || dict.empty())
		return false;
	for (size_t i = 1; i<s.size(); ++i)
	{
		if (dict.find(s.substr(s[0], s[i])) != dict.end() && \
			dict.find(s.substr(s[i+1], s[s.size()-1])) != dict.end())
			return true;
	}
	return false;
}

int main()
{
	string s = "leetcode";
	unordered_set<string> dict = { "leet", "code" };
	cout << wordBreak(s, dict) << endl;
	return 0;
}
