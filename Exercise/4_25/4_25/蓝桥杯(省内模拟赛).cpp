#if 0
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
void BackTrack(vector<string>& res, string str, int left, int right)
{
	if (left == 0 && right == 0)
	{
		res.push_back(str);
		return;
	}
	if (left > 0)
		BackTrack(res, str + '(', left - 1, right + 1);//当给结果中加入一个‘(’，就要保证在后边会有一个‘)’与其匹配
	if (right > 0)
		BackTrack(res, str + ')', left, right - 1);
}
vector<string> generateParenthesis(int n) {
	vector<string> res;
	BackTrack(res, "", n, 0);//第一个填入的一定是‘(’
	return res;
}

void CharReSort(string str,map<string,int>& res)
{
	sort(str.begin(), str.end());
	do
	{
		if (res.find(str) == res.end())
			res.insert(make_pair(str,0));
	} while (next_permutation(str.begin(),str.end()));
}

int main()
{
	/*
	cout << generateParenthesis(4).size() << endl;
	*/
	string str = "lanqiao";
	map<string,int> res;
	CharReSort(str,res);
	cout << res.size() << endl;
	int a;
	cin >> a;
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

int main()
{
	int n, count = 0;
	int a, b, c;
	cin >> n >> a >> b >> c;
	for (int i = 1; i <= n; ++i)
		if (i%a != 0 && i%b != 0 && i%c != 0)
			count++;
	cout << count << endl;
	cin >> a;
	return 0;
}
#endif

#if 0

#include<iostream>
#include<string>
using namespace std;

void encryption(string& str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i]<120)
			str[i] = str[i] + 3;
		else
			str[i] = 'a' + (str[i] + 3 - 123);
	}
}
int main()
{
	string str;
	cin >> str;
	encryption(str);
	cout << str << endl;
	cin >> str;
	return 0;
}
#endif


#if 0
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, m;
	int r, c;
	cin >> n >> m >> r >> c;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	int pos = 1;
	int top = 0, down = n - 1, left = 0, right = m - 1;
	while (pos <= n*m)
	{
		//向右填入一行
		for (int i = left; pos <= n*m && i <= right; ++i)
			arr[top][i] = pos++;
		top++;
		//向下填入一行
		for (int i = top; pos <= n*m && i <= down; ++i)
			arr[i][right] = pos++;
		right--;
		//向左填入一行
		for (int i = right; pos <= n*m && i >= left; --i)
			arr[down][i] = pos++;
		down--;
		//向上填入一行
		for (int i = down; pos <= n*m && i >= top; --i)
			arr[i][left] = pos++;
		left++;
	}
	cout << arr[r - 1][c - 1] << endl;
	cin >> n;
	return 0;
}
#endif

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> dp(m+1,vector<int>(n));
	for (int i = 0; i < dp[m].size(); ++i)
		dp[m][i] = 1;
	for (int i = m - 1; i >= 0; i--)
	{
		if ((i & 1) == 1)
			for (int j = 1; j < n; ++j)
				dp[i][j] = (dp[i][j - 1] + dp[i + 1][j - 1]) % 10000;
		else
			for (int j = n - 2; j >= 0; --j)
				dp[i][j] = (dp[i][j + 1] + dp[i + 1][j + 1]) % 10000;
	}
	cout << dp[0][0] << endl;
	cin >> m;
	return 0;
}



#include<iostream>
#include<cmath>
using namespace std;
int x[100], y[100], r[100], n, maxn;
bool vis[100], sign[100][100];
void dfs(int step){
	if (step > n) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) {
				sum += (r[i] * r[i]);
			}
		}
		maxn = max(sum, maxn);
		return;
	}
	//	剪枝 
	vis[step] = false;

	dfs(step + 1);
	for (int i = 1; i < step; i++) {
		if (vis[i] && !sign[i][step]) {
			return;
		}
	}
	vis[step] = true;

	dfs(step + 1);
}

int main() {
	cin >> n;
	//   输入数据 
	for (int i = 1; i <= n; i++){
		cin >> x[i] >> y[i] >> r[i];
	}
	//   数据序列化 
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++)
		{
			bool result = ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) > (r[i] + r[j])*(r[i] + r[j]));
			sign[i][j] = result;
			sign[j][i] = result;
		}
	}
	dfs(1);
	cout << maxn << endl;
}