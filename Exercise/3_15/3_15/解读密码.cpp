// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	string info;
	while (getline(cin, info))
	{
		string res;
		for (const auto c : info)
			if (c >= '0' && c <= '9')
				res.push_back(c);
		cout << res << endl;
	}
	return 0;
}