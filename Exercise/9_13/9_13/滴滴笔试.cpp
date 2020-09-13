#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	string s, temp;
	cin >> n;
	getline(cin, temp);
	getline(cin, s);
	int pos = 0;
	if (n > s.size())
		reverse(s.begin(), s.end());
	else
	{
		while (s.size() - pos >= n)
		{
			reverse(s.begin() + pos, s.begin() + pos + n);
			pos += n;
		}
		reverse(s.begin() + pos, s.end());
	}
	cout << s << endl;
	return 0;
}
#endif


#if 0
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T = 0, n = 0;
	int m = 0, k = 0;
	cin >> T;
	string s1 = "Yes";
	while (T--)
	{
		int a = 0, b = 0, c = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < m; ++i)
			cin >> a >> b >> c;
		cout << s1 << endl;
	}
	return 0;
}
#endif