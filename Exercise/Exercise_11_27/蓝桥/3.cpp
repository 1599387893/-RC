#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int key = 0;
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		sort(v.begin(),v.end());
		for (int i = 0; i < v.size(); ++i)
		{
			if (k == 1)
			{
				key = v[i];
				break;
			}
			else if (v[i] != v[i + 1])
				k--;
		}
		cout << key << endl;
	}
	return 0;
}