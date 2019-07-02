//#include<iostream>
//#include<string>
//using namespace std;
//
//int find_root(int& num)
//{
//	int root = 0;
//	while (num >= 10)
//	{
//		root = 0;
//		while (num)
//		{
//			root += num % 10;
//			num /= 10;
//		}
//		num = root;
//	}
//	return root;
//}
//
//int main()
//{
//	string num;
//	while (cin >> num)
//	{
//		int sum = 0;
//		for (auto t = num.begin(); t != num.end(); t++)
//		{
//			sum = sum + (*t) - '0';
//			cout << find_root(sum) << endl;
//		}
//	}
//	return 0;
//}

#include<iostream>
#include<string>
using namespace std;

int solve(string s){
	int sum = 0;
	for (int i = 0; i<s.length(); i++){
		sum = sum + (int)(s[i] - 48);
	}
	return (sum - 1) % 9 + 1;
}

int main()
{
	string num;
	while (cin >> num)
	{
		cout<<solve(num)<<endl;
	}
	return 0;
}