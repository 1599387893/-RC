

#if 0
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int a_count = 0;
		int b_count = 0;
		int i = 0;
		for (; i < b.size(); ++i)
		{
			a_count = count(a.begin(), a.end(), b[i]);
			b_count = count(b.begin(), b.end(), b[i]);
			if (a_count < b_count)
			{
				cout << "No" << endl;
				break;
			}
			i += b_count;
		}
		if (i == b.size())
			cout << "Yes" << endl;
	}
	return 0;
}




#endif