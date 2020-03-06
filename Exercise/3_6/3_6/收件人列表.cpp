// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n;
	string msg;
	vector<string> res;
	while (cin >> n)
	{
		//cin.sync();
		cin.get();
		while (n--)
		{
			//cin.sync();
			getline(cin, msg);
			auto pos1 = msg.find(',');
			auto pos2 = msg.find(' ');
			if (pos1 == string::npos && pos2 == string::npos)
				res.push_back(msg);
			else
				res.push_back("\"" + msg + "\"");
			msg.clear();
		}
		cout << res[0];
		for (int i = 1; i < res.size(); ++i)
			cout << ", " << res[i];
		cout << endl;
		res.clear();
	}
	return 0;
}