#if 0
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), (char)('z' + 1));
		vector<int> array;
		for (int i = 0; i < len2; ++i)
			array.push_back(s2[i] - s1[i]);
		int res = 0;
		for (int i = len1; i <= len2; ++i)
			for (int j = 0; j < i; ++j)
				res += array[j] * pow(26, i - 1 - j);
		cout << res - 1 << endl;
	}
	return 0;
}
#endif