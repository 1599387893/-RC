#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<vector<int>> dp(s.size(), vector<int>(s.size()));
	int maxLength = 1;
	int pos = 0;
	for (int i = 0; i < s.size(); ++i)
		dp[i][i] = 1;
	for (int i = s.size() - 2; i >= 0; --i)
	{
		for (int j = i; j < s.size(); ++j)
		{
			if (j > 0 && s[i] == s[j] && (dp[i + 1][j - 1] || i == j - 1))
				dp[i][j] = 2 + dp[i + 1][j - 1];
			if (dp[i][j] >= maxLength)
			{
				maxLength = dp[i][j];
				pos = i;
			}
		}
	}
	cout << s.substr(pos, maxLength) << endl;
	return 0;
}


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	string s;
	cin >> s;
	if (s.size() == 0)
	{
		cout << "" << endl;
	}
	else
	{
		string res, temp;
		unordered_map<int, int> um;
		for (int i = 0; i < s.size(); ++i)
		{
			if (um.find(s[i]) == um.end())
			{
				temp += s[i];
				um[s[i]] = temp.size() - 1;
			}
			else
			{
				temp.erase(0, um[s[i]]);
			}
			if (temp.size() > res.size())
				res = temp;
		}
		cout << res << endl;
	}
	return 0;
}
#endif

#if 0 
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string patt, str;
	while (cin >> str >> patt)
	{
		int pos1 = 0;
		int pos2 = 0;
		while (pos1 < patt.size() && pos2 < str.size())
		{
			if (patt[pos1] == '*')
			{
				if (pos1 + 1 < patt.size() && patt[pos1 + 1] == str[pos2])
					pos1++;
				while (pos1 > 0 && pos2 < str.size() && (patt[pos1 - 1] == str[pos2] || patt[pos1 - 1] == '.'))
					pos2++;
				pos1++;
			}
			else if (patt[pos1] == '.' || patt[pos1] == str[pos2])
			{
				pos1++;
				pos2++;
			}
			else
				break;
		}
		if (pos1 == patt.size() && pos2 == str.size())
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
#endif



class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		int begin = 0, size = 1;
		vector<vector<bool>> dp(n, vector<bool>(n)); //dp[i][j]:表示i到j之间是否为回文串
		for (int i = 0; i < n; ++i) //单个元素一定为回文串
			dp[i][i] = true;

		//先行再列：保证j不会小于i
		for (int j = 1; j < n; ++j)
		{
			for (int i = j - 1; i >= 0; --i)
			{
				if (s[i] != s[j])
					dp[i][j] = false;
				else
				{
					if (j - i < 3)
						dp[i][j] = true;
					else   //在[i+1, ...,j-1]中是回文子串，或者[i+1,..,j-1]之间只有一个元素或者没有元素
						dp[i][j] = dp[i + 1][j - 1];
				}
				if (dp[i][j] && j - i + 1 > size)
				{
					size = j - i + 1;
					begin = i;
				}
			}
		}
		return s.substr(begin, size);
	}
};