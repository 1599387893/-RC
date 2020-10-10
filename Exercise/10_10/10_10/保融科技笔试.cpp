#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	auto pos = s.rfind(' ');
	if (pos != string::npos)
		cout << s.size() - pos << endl;
	else
		cout << 0 << endl;
	return 0;
}

#endif 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> arr;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int cur = 0;
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		cur += arr[i];
		res = max(res, cur);
		if (cur < 0)
			cur = 0;
	}
	return res;
}

