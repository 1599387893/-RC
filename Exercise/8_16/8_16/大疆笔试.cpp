//sort(time.begin(), time.end(), \
	[](const pair<pair<int, int>, int>& p1, const pair<pair<int, int>, int>& p2) \
{ return p1.first.first < p2.first.first});

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int GoXMinTime(const vector<pair<pair<int, int>, int>>& time, int X)
{
	for (const auto& p : time)
	{
		if (p.first.first == 0 && p.first.second == X)
			return p.second;
	}
	return 0;
}
int main()
{
	int N = 0, P = 0;
	vector<pair<pair<int, int>, int>> time(P);
	int A = 0, B = 0, T = 0;
	int X = 0;
	while (P--)
	{
		cin >> A >> B >> T;
		time.push_back(pair<pair<int, int>, int>(pair<int, int>(A, B), T));
	}
	cin >> X;
	cout << GoXMinTime(time, X) << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Less(const pair<int, int>& p1, const pair<int, int>& p2)
{
	return p1.second < p2.second;
}
int main()
{
	int N = 0, X = 0;
	cin >> N >> X;
	vector<pair<int, int>> worth(N);
	int a = 0, b = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b;
		worth.push_back(pair<int, int>(a, b));
	}
	sort(worth.begin(), worth.end(), Less);
	vector<int> dp(X + 1);//dp[i]表示第i天可达到的成就和的最大值 dp[i] = max(dp[i-1],dp[i-worth[pos]]);
	int pos = 0;
	for (int i = 1; i <= X; ++i)
		if (i >= worth[pos].second)
			dp[i] = max(dp[i - 1], dp[i - worth[pos].second] + worth[pos].first);
	cout << dp.back() << endl;
	return 0;
}*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	int K = 0, pos = -1;
	cin >> str >> K;
	vector<int> arr(str.size());
	for (int i = 1; i < str.size(); ++i)
		for (int j = 0; j < i; ++j)
			if (str[i] < str[j])
			{
		arr[i]++;
		if (arr[i] == K && pos == -1)
			pos = i;
			}
	char c = str[pos];
	for (int i = pos; i >= 0; --i)
		if (c < str[i])
			str.erase(i,1);
	cout << atoi(str.c_str()) << endl;
	system("pause");
	return 0;
}