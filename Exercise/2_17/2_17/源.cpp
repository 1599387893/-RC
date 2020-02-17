#include<iostream>
#include<string>
#include<vector>
using namespace std;

#if 0
int main()
{
	string s1, s2;
	while (getline(cin, s1))
	{
		string ret;
		getline(cin, s2);
		vector<int> hash(256);
		for (size_t i = 0; i < s2.size(); ++i)
			hash[s2[i]]++;

		for (size_t i = 0; i < s1.size(); ++i)
			if (hash[s1[i]] == 0)
				ret += s1[i];
		cout << ret << endl;
	}
	return 0;
}



//方法二
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2, res;
	getline(cin, s1);
	getline(cin, s2);
	for (size_t i = 0; i < s1.size(); ++i)
		if (s2.find(s1[i]) == string::npos)
			res += s1[i];
	cout << res << endl;
	return 0;
}
#endif

//最大连续和

#if 0
#include<iostream>
using namespace std;

int main()
{
	int n, temp;
	int max = -2130000000, sum = 0;
	cin >> n;
	while (n--)
	{
		cin >> temp;
		sum += temp;
		if (sum > max)
			max = sum;
		if (sum < 0)
			sum = 0;
	}
	cout << max << endl;
	return 0;
}
#endif
//方法二
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, temp;
	int sum = -2130000000, res = -2130000000;
	cin >> n;
	while (n--)
	{
		cin >> temp;
		sum = max(sum + temp, temp);
		res = max(res, sum);
	}
	cout << res << endl;
	return 0;
}