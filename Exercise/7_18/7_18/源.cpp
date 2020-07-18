#if 0 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int n = 132;
	string s = to_string(n);
	sort(s.begin(), s.end());
	do
	{
		cout << s << endl;
	}while(next_permutation(s.begin(),s.end()));
	system("pause");
	return 0;
}
#endif