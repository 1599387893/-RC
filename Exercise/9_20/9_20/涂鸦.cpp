#if 0
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int Count(vector<int>& arr)
{
	unordered_map<int,int> um;
	for (auto n : arr)
		um[n]++;
	int res = 0;
	for (auto p : um)
	{
		if (p.first != 1)
			res += p.first + 1;
		else
			res += p.second + 1;
	}
	return res;
}
int main()
{
	vector<int> arr{4,1,4,2};
	cout << Count(arr) << endl;
	return 0;
}
#endif


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<vector<long>> arr(2, vector<long>(n));
	for (int i = 0; i < 2 * n; ++i)
		cin >> arr[i / n][i % n];

	vector<vector<long>> leftMax(arr);
	for (int i = 0; i < 2; ++i)
		for (int j = 1; j < n; ++j)
			leftMax[i][j] = max(leftMax[i][j], leftMax[i][j - 1]);

	vector<vector<long>> dp(arr);
	for (int i = 1; i < n; ++i)
	{
		dp[0][i] += max(dp[1][i - 1], leftMax[1][i]);
		dp[1][i] += max(dp[0][i - 1], leftMax[0][i]);
	}
	cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
	return 0;
}

#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int CountReverse(string& s)
{
	int OneCount = count(s.begin(), s.end(),'1');
	int ZeroCount = count(s.begin(), s.end(), '0');
	auto pos1 = s.find('1');
	auto pos2 = s.rfind('1');
	if (pos2 - pos1 + 1== OneCount && (pos1 == 0 || pos2 == s.size() - 1))
		return 0;
	return min(OneCount, ZeroCount);
}

int main()
{
	int n = 0;
	cin >> n;
	string s;
	while (n--)
	{
		cin >> s;
		if (s.size() == 1 || count(s.begin(), s.end(), '0') == s.size() || count(s.begin(), s.end(), '1') == s.size())
			cout << 0 << endl;
		else
			cout << CountReverse(s) << endl;
	}
	return 0;

}
#endif