#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Is24(int* arr, int arrLen, int pos, int res)
{
	if (res == 24 && pos == arrLen) return true;
	if (pos >= arrLen) return false;
	return Is24(arr, arrLen, pos + 1, res + arr[pos]) ||
		Is24(arr, arrLen, pos + 1, res - arr[pos]) ||
		Is24(arr, arrLen, pos + 1, res * arr[pos]) ||
		Is24(arr, arrLen, pos + 1, res / arr[pos]);
}
bool Game24Points(int* arr, int arrLen) {
	// write code here
	return Is24(arr, arrLen, 0, 0);
}


int GetCoinCount(int N) {
	// write code here
	N = 1024 - N;
	if (N == 0)  return 0;
	if ((N == 1) || (N == 4) || (N == 16) || (N == 64))  return 1;
	vector<int> coins{ 64, 16, 4, 1 };
	int res = 0;
	int pos = 0;
	while (N > 0 && pos < coins.size())
	{
		while (N > coins[pos])
		{
			N -= coins[pos];
			res++;
		}
		pos++;
	}
	return res;
}
int main()
{
	string s = "abc";
	string temp = s;
	reverse(s.begin(), s.end());
	int arr[] = { 7, 2, 1, 10 };
	cout << GetCoinCount(200);
}





/*
class Solution {
public:
	/**
	*
	* @param s string字符串
	* @return bool布尔型
	
	bool IsValidExp(string s) {
		// write code here
		if (s.empty()) return true;
		if (s.size() % 2) return false;
		stack<char> sta;
		int pos = 1;
		sta.push(s[0]);
		while (!sta.empty() || pos != s.size())
		{
			if ((s[pos] == '(') || (s[pos] == '[') || (s[pos] == '{'))
				sta.push(s[pos]);
			else
			{
				if (s[pos] == ')')
				{
					if (sta.top() == '(')
						sta.pop();
					else
						break;
				}
				else if (s[pos] == ']')
				{
					if (sta.top() == '[')
						sta.pop();
					else
						break;
				}
				else
				{
					if (sta.top() == '{')
						sta.pop();
					else
						break;
				}
			}
		}
		return !sta.empty();
	}
};



class Solution {
public:
/**
*
* @param N int整型
* @return int整型

int GetCoinCount(int N) {
	// write code here
	N = 1024 - N;
	if (N == 0)  return 0;
	if ((N == 1) || (N == 4) || (N == 16) || (N == 64))  return 1;
	vector<int> coins{ 1, 4, 16, 64 };
	vector<int> dp(N + 1, 1);
	for (int i = 2; i < dp.size(); ++i)
	{
		dp[i] = i;
		for (int j = 1; j < coins.size(); ++j)
		{
			dp[i] = min(dp[i], min(dp[i - 1], i - coins[j] >= 0 ? dp[i - coins[j]] : dp[i - 1]));
		}
	}
	return dp.back();
}
};*/