#if 0
#include<iostream>
#include<vector>
using namespace std;

int gcd(int a,int b)
{
	int temp ;
	while (temp = a%b)
	{
		a = b;
		b = temp;
	}
    return b;
}
int main()
{
    int n;
    int a;
    while(cin>>n>>a)
    {
        vector<int> m(n);
        for(int i = 0;i<n;++i)
            cin>>m[i];
        
        for(int i = 0;i<n;++i)
        {
            if(m[i]<=a)
                a+=m[i];
            else
                a+=gcd(a,m[i]);
        }
        cout<<a<<endl;
    }
}



#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<int> hash(256, 0);
	string s;
	while (cin >> s)
	{
		for (int i = 0; i<s.size(); ++i)
			hash[s[i]]++;
		for (int i = 0; i<s.size(); ++i)
			if (hash[s[i]] == 1)
			{
			cout << s[i] << endl;
			break;
			}
	}
	return 0;
}
#endif