#include<iostream>
#include<vector>
using namespace std;
#if 0
//1.微信红包
int getValue(vector<int> gifts, int n) {
	// write code here
	sort(gifts.begin(), gifts.end());
	int count = 0;
	for (int i = 0; i < n; i++){
		if (gifts[i] == gifts[n / 2])
			count++;
	}
	if (count > n / 2)
		return gifts[n / 2];
	return 0;
}
int main()
{
	vector<int> v = { 1, 2, 3, 2, 2 };
	int n = 5;
	cout << getValue(v, n) << endl;
	system("pause");
	return 0;
}
#endif

//2.计算字符串的距离

#if 0
#include<iostream>
#include <string>
#include <vector>
using namespace std;
int calStringDistance(string a, string b){
	int n = (int)a.size(), m = (int)b.size();
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	dp[0][0] = 0;//dp[x][y]代表将a字符串前x个字符修改成b字符串前y个字符
	for (int i = 1; i <= m; ++i) dp[0][i] = i;
	for (int i = 1; i <= n; ++i) dp[i][0] = i;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int one = dp[i - 1][j] + 1, two = dp[i][j - 1] + 1, three = dp[i - 1][j - 1];
			if (a[i - 1] != b[j - 1]) three += 1;
			dp[i][j] = min(min(one, two), three);
		}
	}
	return dp[n][m];
}
int main(){
	string a, b;
	while (cin >> a >> b)
		cout << calStringDistance(a, b) << endl;
	return 0;
}
#endif