//#include<iostream>
//#include<string>
//using namespace std;
//
//int solve(string s)
//{
//	int sum = 0;
//	for (auto t = s.begin(); t != s.end(); t++)
//				sum = sum + (*t) - '0';
//	return sum; 
//}
//
//void Judge(string body, string vessel)
//{
//	int body_num = solve(body);
//	int vessel_num = solve(vessel);
//	if (body_num>(vessel_num*6.28))
//		cout << "No" << endl;
//	else
//		cout << "Yes" << endl;
//
//}
//int main()
//{
//	string body;
//	string vessel;
//	while (cin >> body)
//	{
//		cin >> vessel;
//		Judge(body, vessel);
//	}
//	return 0;
//}

#include<iostream>
using namespace std;

int Add(int num1, int num2)
{
	int ret = 0;
	for (int i = 0; i<num1; i++)
		ret++;
	for (int i = 0; i<num2; i++)
		ret++;
	return ret;
}
int main()
{
	int num1 = 0;
	int num2 = 0;
	while (cin >> num1)
	{
		cin >> num2;
		cout << Add(num1, num2) << endl;
	}
	return 0;
}