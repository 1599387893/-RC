#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T = 0, L = 0, n = 0;
	cin >> T;
	while (T--)
	{
		cin >> L >> n;
		int l = 0, r = 0;
		vector<pair<int, int>> arr(n);
		vector<int> res(L, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> l >> r;
			arr[i] = pair<int, int>(l, r);
		}
		for (auto p : arr)
		{
			for (int i = p.first; i <= p.second; ++i)
				res[i - 1]++;
		}
		for (auto num : res)
			cout << num << " ";
		cout << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	int T = 0, n = 0, m = 0;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		vector<int> nWorth(n);
		vector<int> mWorth(m);
		for (int i = 0; i < n; ++i)
			cin >> nWorth[i];
		for (int i = 0; i < m; ++i)
			cin >> mWorth[i];

		vector<int> vp(n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				if (nWorth[i] <= mWorth[j] && (vp[i] == 0 || mWorth[j] - nWorth[i] < vp[i]))
					vp[i] = j;
		}
		
		cout << endl;
	}
	return 0;
}
#endif

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	cout << pow(2, 3) << endl;
	int T = 0, n = 0, m = 0;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		map<int, int> nWorth;
		map<int, int> mWorth;
		int temp = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			nWorth.insert(pair<int, int>(temp, i));
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> temp;
			mWorth.insert(pair<int, int>(temp, i));
		}
		vector<int> vp(n, -2);
		map<int, int>::iterator pos = mWorth.begin();
		for (auto it : nWorth)
		{
			while (pos != mWorth.end())
			{
				if ((*pos).first >= it.first)
				{
					vp[it.second] = (*pos).second;
					break;
				}
				pos++;
			}
		}
		for (auto pos : vp)
			cout << pos + 1 << " ";
		cout << endl;
	}
	return 0;
}