#if 0
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int max = 0;
		string con;
		string request;
		while (n--)
		{
			getline(cin, request);
			if (request[2] == 'c')
				con.push_back(request[0]);
			else
				con.erase(con.find(request[0]));
			max = max<con.size() ? con.size() : max;
		}
		cout << max << endl;
	}
	return 0;
}
#endif