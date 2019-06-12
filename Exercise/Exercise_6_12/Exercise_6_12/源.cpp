#include<iostream>
#include<string>
#include<vector>
using namespace std;

void findcursor(int ts, string touch)
{
	int cursor = 1;
	if (ts <= 4)
	{
		vector<int> window(ts);
		for (int i = 0; i<ts; ++i)
			window[i] = i + 1;
		for (int i = 0; i<touch.size(); ++i)
		{
			if (touch[i] == 'U')
			{
				if (cursor == 1)
					cursor = ts;
				else
					--cursor;
			}
			if (touch[i] == 'D')
			{
				if (cursor == ts)
					cursor = 1;
				else
					++cursor;
			}
		}
		for (int i = 0; i<window.size(); ++i)
			cout << window[i] << " ";
		cout << endl;
		cout << cursor << endl;
	}
	else
	{
		vector<int> window(4);
		for (int i = 0; i<4; ++i)
			window[i] = i + 1;
		for (int i = 0; i<touch.size(); ++i)
		{
			if (touch[i] == 'U')
			{
				if (cursor == 1)
				{
					cursor = ts;
					window[3] = ts;
					window[2] = ts - 1;
					window[1] = ts - 2;
					window[0] = ts - 3;
				}
				else
				{
					--cursor;
					if (cursor<window[0])
					{
						window[3] = cursor;
						window[2] = cursor - 1;
						window[1] = cursor - 2;
						window[0] = cursor - 3;
					}
				}
			}
			if (touch[i] == 'D')
			{
				if (cursor == ts)
				{
					cursor = 1;
					window[3] = 4;
					window[2] = 3;
					window[1] = 2;
					window[0] = 1;
				}
				else
				{
					++cursor;
					if (cursor>window[3])
					{
						window[0] = cursor;
						window[1] = cursor + 1;
						window[2] = cursor + 2;
						window[3] = cursor + 3;
					}
				}
			}
		}
		for (int i = 0; i<4; ++i)
			cout << window[i] << " ";
		cout << endl;
		cout << cursor << endl;
	}
}
int main()
{
	int Totalsong = 0;
	while (cin >> Totalsong)
	{
		if (Totalsong <= 0)
			continue;
		string touch;
		fflush(stdin);
		getline(cin, touch);
		findcursor(Totalsong, touch);
	}
	return 0;
}