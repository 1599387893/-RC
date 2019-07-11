// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void Reciplents_list(vector<string> v)
{
	for (size_t i = 0; i<v.size(); ++i)
	{
		string temp;
		int a = int(v[i].find(','));
		int b = int(v[i].find(' '));
		if ((a>=0) ||(b>=0) )
			temp += '"' + v[i] + '"';
		else
			temp = v[i];
		cout << temp;
		if (i != v.size()-1)
			cout << ", ";
	}
	cout << endl;
}

#if 0
int main()
{
	int n = 0;
	vector<string> v;
	while (cin >> n)
	{
		fflush(stdin);
		v.resize(n);
		for (int i = 0; i<n; ++i)
			getline(cin, v[i]);
		Reciplents_list(v);
	}
	return 0;
}
#endif

// write your code here cpp
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n<1 || n> 90)
			continue;
		int rabbit = 1;
		for (int i = 0; i <= n; ++i)
			rabbit *= 2;
		cout << rabbit << endl;
	}
	return 0;
}