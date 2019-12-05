//1.Ï´ÅÆ
#if 0
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
void Shuffle(stack<int>& s, int& k, int& n)
{
	queue<int> left;
	queue<int> right;
	while (k--)
	{
		for (int i = 0; i<2 * n; ++i, s.pop())
		{
			if ((int)i<n)
				left.push(s.top());
			else
				right.push(s.top());
		}
		for (int i = 0; i < n; ++i)
		{
			s.push(left.front());
			s.push(right.front());
			right.pop();
			left.pop();
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v(2 * n);
		stack<int> s;
		int temp;
		for (int i = 0; i<2 * n; ++i)
			cin >> v[i];
		for (int i = v.size() - 1; i >= 0; --i)
			s.push(v[i]);
		Shuffle(s, k, n);
		for (auto it = 0; it<2 * n; ++it, s.pop())
		{
			temp = s.top();
			cout << temp << " ";
		}
	}
	return 0;
}
#endif
//2. MP3¹â±êÎ»ÖÃ
#if 0
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void Move(int n, string& commd)
{
	if (n <= 4)
	{
		for (int i = 1; i <= n; ++i)
			cout << i << " ";
		cout << endl << commd.size() % n + 1 << endl;
		return;
	}
	vector<int> v = { 1, 2, 3, 4 };
	int loct = 0;
	for (auto i = 0; i < commd.size(); ++i)
	{
		if (commd[i] == 'U')
			loct--;
		else
			loct++;
		if (loct<0)
		{
			if (v[0] == 1)
			{
				for (int i = 3; i >= 0; --i)
					v[3 - i] = n - i;
				loct = 3;
			}
			else
			{
				for (int i = 0; i < 4; ++i)
					v[i]--;
				loct = 0;
			}
		}
		else if (loct>3)
		{
			if (v[3] == n)
			{
				for (int i = 0; i < 4; ++i)
					v[i] = i + 1;
				loct = 0;
			}
			else
			{
				for (int i = 0; i < 4; ++i)
					v[i]++;
				loct = 3;
			}
		}
	}
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl << v[loct] << endl;
}
int main()
{
	int n;
	string commd;
	while (cin >> n >> commd)
		Move(n, commd);
	return 0;
}
#endif