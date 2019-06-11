#if 0
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}
#include<iostream>
#include<string>
using namespace std;

int count_same_str(string s1, string s2)
{
	if (s1.size() < s2.size())
		s1.swap(s2);
	const char* p1 = s1.c_str();
	const char* p2 = s2.c_str();
	int ret = 0;
	while (*p1 != '\0')
	{
		int temp = 0;
		const char* pp1 = p1;
		const char* pp2 = p2;
		while (*pp1 == *pp2 && *pp1 != '\0' && *pp2 != '\0')
		{
			++temp;
			pp1++;
			pp2++;
		}
		if (temp>ret)
			ret = temp;
		p1++;
	}
	return ret;
}
int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
		cout << count_same_str(s1, s2) << endl;
	return 0;
}
#endif
#include<iostream>
#include<vector>
using namespace std;
int main(){
	string str1, str2;
	while (cin >> str1 >> str2){
		int len1 = str1.size();
		int len2 = str2.size();
		int max = 0;
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i <= len1; ++i){
			for (int j = 1; j <= len2; ++j){
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > max)
					max = dp[i][j];
			}
		}
		cout << max << endl;
	}
	return 0;
}