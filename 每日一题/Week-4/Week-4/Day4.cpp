#include<iostream>
#include<string>
using namespace std;
#if 0

//1.小易的升级之路
#include<iostream>
#include<vector>
using namespace std;
int Div(int b, int a)
{
	int c = 0;
	while(c = a % b)
	{
		a = b;
		b = c;
	}
	return b;
}
void AddPower(int& b,int& a)
{
	if(a>=b)
		a+=b;
	else
		a+=Div(b,a);
}
int main()
{
	int n,a;
	while(cin>>n>>a)
	{
		vector<int> v(n);
		for(int i = 0; i < n;++i)
			cin>>v[i];
		for(int i = 0;i < n;++i)
			AddPower(v[i],a);
		cout<<a<<endl;
	}
	return 0;
}
#endif

//2.找出字符串中第一个只出现一次的字符
#if 0
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int v[256] = { 0 };
		for (const auto& e : s)
			++v[e];
		int i = 0;
		for (i = 0; i < s.size(); ++i)
		{
			if (v[s[i]] == 1)
			{
				cout << s[i] << endl;
				break;
			}
		}
		if (i == s.size())
			cout << "-1" << endl;
	}
	return 0;
}
#endif
