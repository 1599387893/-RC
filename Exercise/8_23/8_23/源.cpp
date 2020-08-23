#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> heigh;
	cin >> n;
	heigh.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> heigh[i];
	int res = 0;
	bool b = true;
	while ((int)count(heigh.begin(), heigh.end(), 0) < heigh.size())
	{
		bool b = false;
		for (int i = 0; i< heigh.size(); ++i)
		{
			if (heigh[i] > 0)
			{
				heigh[i]--;
				b = true;
			}
			else
			{
				if (heigh[i - 1] == 0 && b && i != heigh.size() - 1)
					res++;
				b = false;
			}
		}
		cout << res << endl;
		res++;
	}
	cout << res << endl;
	return 0;
}