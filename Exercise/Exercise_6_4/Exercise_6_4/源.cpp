#if 0
#include<iostream>
#include<vector>
using namespace std;

int count_bag(vector<int>v)
{
    int ret = 0;
    while(v.size())
    {
        int add = 0;
        int mul = 0;
        for(int i = 0;i<v.size();++i)
        {
            add+=v[i];
            mul*=v[i];
        }
        if(add>mul)
            ++ret;
        v.erase(v.begin(),v.begin()+1);
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;++i)
        cin>>v[i];
    int count = count_bag(v);
    cout<<count<<endl;
    
    return 0;
}
#endif

#include<iostream>
#include<vector>
using namespace std;

int count_bag(vector<int>v)
{
	int ret = 0;
	while (v.size())
	{
		int add = 0;
		int mul = 1;
		for (int i = 0; i<v.size(); ++i)
		{
			add += v[i];
			mul *= v[i];
		}
		if (add>mul)
			++ret;
		v.erase(v.begin(), v.begin() + 1);
	}
	return ret;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		for (int i = 0; i<n; ++i)
			cin >> v[i];
		int count = count_bag(v);
		cout << count << endl;
	}

	return 0;
}