#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

#if 0
int main()
{
	int n;
	string s1, s2;
	cin >> n;
	unordered_map<string, string> pre;
	unordered_map<string, string> next;
	for (int i = 0; i < n; ++i)
	{
		cin >> s1 >> s2;
		pre[s2] = s1;
		next[s1] = s2;
	}
	//ÕÒµ½Á´±íÍ·
	string head = pre.begin()->second;
	while (pre.find(head) != pre.end())
		head = pre[head];
	while (next.find(head) != next.end())
	{
		cout << head << endl;
		head = next[head];
	}
	cout << head << endl;
	return 0;
}
#endif

