#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int res = 0;
	int cur = 0;
	unordered_map<char, int> um;
	for (int i = 0; i < s.size(); ++i)
	{
		if (um.find(s[i]) == um.end())
			cur++;
		else
			cur = i - um[s[i]];
		um[s[i]] = i;
		res = max(res, cur);
	}
	cout << res << endl;
	return 0;
}