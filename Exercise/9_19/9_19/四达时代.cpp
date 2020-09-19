#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N = 0;
	int InsertErrCount = 0, EraseErrCount = 0;
	int EffectCount = 0;
	int begin = 0, end = 0;
	cin >> N;
	vector<char> arr(N);
	string str;
	while (cin >> str)
	{
		if (str == "END")
			break;
		if (str == "P")
		{
			if (EffectCount == N - 1)
			{
				InsertErrCount++;
				continue;
			}
			char c;
			cin >> c;
			arr[end % N] = c;
			end++;
			EffectCount++;
		}
		else if (str == "D")
		{
			if (EffectCount == 0)
			{
				EraseErrCount++;
				continue;
			}
			arr[begin] = '0';
			begin++;
			EffectCount--;
		}
	}
	cout << InsertErrCount << endl;
	cout << EraseErrCount << endl;
	if (EffectCount == 0)
	{
		cout << "EMPTY" << endl;
	}
	else
	{
		int i = 0;
		while (i < EffectCount)
		{
			cout << arr[begin % N];
			begin++;
			i++;
		}
	}
	system("pause");
	return 0;

}


/*
3
P a
P b
P c
D
P d
END
*/