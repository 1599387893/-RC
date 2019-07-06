#if 0
// write your code here cpp
#include<iostream>
using namespace std;

int Find_fake(long long int n)
{
	int count = 0;
	while (n >= 2)
	{
		n >>= 1;
		count++;
	}
	return count;
}

int main()
{
	long long int n = 1;
	//&& n != 0
	while (cin >> n && n!=0)
		cout << Find_fake(n) << endl;
	return 0;
}



#include <iostream>
using namespace std;


int solve(int n)
{
	if (n == 1)
		return 0;
	if (n <= 3)
		return 1;
	else
		return solve((n + 2) / 3) + 1;
}
int main()
{
	int n;
	while (cin >> n && n != 0)
		cout << solve(n) << endl;
	return 0;
}
#endif

#include<iostream>
#include<vector>

int getFirstUnFormedNum(vector<int> arr, int len) 
{
	set<int> S;
	vector<int> tmp;
	int mi = 0x7fffffff;
	for (int i = 0; i < len; ++i) 
	{
		if (arr[i] <  mi) 
			mi = arr[i];//保存最小元素，即小边界
		
		for(set<int>::iterator it = S.begin(); it != S.end(); ++it) 
			tmp.push_back(*it + arr[i]);
		
		for(unsigned int i = 0; i < tmp.size(); ++i)
			S.insert(tmp[i]);
		
		S.insert(arr[i]);
		tmp.clear();
	}
	for(int i = mi;; ++i) 
		if (S.find(i) == S.end()) 
			return i;
	return -1;
}

int main()
{
	vector<int> arr;
	getFirstUnFormedNum(arr, arr.size());
}