

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void Reverse(int& n)
{
	int res = 0;
	while (n)
	{
		res = res * 10 + n % 10;
		n /= 10;
	}
	n = res;
}
void SetFive(int& n)
{
	string res = "";
	while (n)
	{
		res = res + to_string(n % 5);
		n /= 5;
	}
	reverse(res.begin(), res.end());
	n = atoi(res.c_str());
}
int main()
{
	int n = 0;
	cin >> n;
	//ÄæÐò
	Reverse(n);
	SetFive(n);
	cout << n << endl;
	Reverse(n);
	cout << n << endl;
	return 0;
}

#endif

#include <iostream>
#include <vector>
using namespace std;

vector<int> hurt;

int KillBoss(int pos, int m)
{
	if (m == 0)
		return 1;
	int res = 0;
	for (int i = pos; i < hurt.size(); ++i)
		res += KillBoss(i + 1, m - hurt[i]);
	return res;
}
int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	hurt.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> hurt[i];
	int res = 0;
	for (auto n : hurt)
		if (m % n == 0) res++;
	res += 2 * KillBoss(0, m);
	cout << res % (1 + 7) << endl;
	return 0;
}