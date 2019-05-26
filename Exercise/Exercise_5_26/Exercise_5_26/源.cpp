//#include<iostream>
//#include<string>
//using namespace std;
//
//
////int StrToInt(string str)
////{
////	int size = str.size();
////	long int retValue = 0;
////	for (int i = size - 1; i >= 0; --i)
////	{
////		if (str[i] >= '0' && str[i] <= '9' )
////		{
////			retValue += str[i] * (pow(10, size - i - 1));
////		}
////		else
////		{
////			retValue = 0;
////			break;
////		}
////	}
////	return retValue;
////}
//
//int StrToInt1(string str)
//{
//	int ret = 0;
//	int flag1 = 0, flag2 = 0;
//	int i = 0;
//	for (; i < str.size(); i++){
//		if (str[i] == '+'){
//			flag1 = 1;
//			continue;
//		}
//		if (str[i] == '-'){
//			flag2 = -1;
//			continue;
//		}
//
//		if (str[i] <= '9' && str[i] >= '0'){
//			ret = 10 * ret + str[i] - '0';
//		}
//		else
//			return 0;
//	}
//	if (flag1 == 1 && flag2 == -1)
//		return 0;
//	if (flag1 == 0 && flag2 == -1)
//		return (0 - ret);
//	return ret;
//
//}
//int StrToInt2(string str)
//{
//	int size = str.size();
//	int retValue = 0;
//	int flag1 = 0;
//	int flag2 = 0;
//
//	for (int i = 0; i < size; ++i)
//	{
//		if (str[i] == '+')
//		{
//			flag1 = 1;
//			continue;
//		}
//		if (str[i] == '-')
//		{
//			flag2 = -1;
//			continue;
//		}
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			retValue = 10 * retValue + str[i] - '0';
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	if (flag1 == 1 && flag2 == -1)
//		return 0;
//	if (flag1 == 0 && flag2 == -1)
//		return (0 - retValue);
//	return retValue;
//
//}
//int main()
//{
//	int ret = 0;
//	string s;
//	cin >> s;
//	ret = StrToInt(s);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//int main()
//{
//	int m = 0123;
//	int n = 123;
//	printf("%o,%o\n",m, n);
//	system("pause");
//	return 0;
//}

#if 0
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;

	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}
	while (m)
	{
		s += table[m%n];
		m /= n;
	}

	if (flag)
		s += '-';

	reverse(s.begin(), s.end());

	cout << s << endl;

	system("pause");
	return 0;
}
#endif

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
	int retValue = 0;
	int m, n;
	int flag = 0;
	vector<int>v;
	cin >> m >> n;

	if (m < 0)
	{
		flag = 1;
		m = 0 - m;
	}

	for (int i = 0; m > 0; ++i)
	{
		v.resize(i + 1);
		v[i] = m%n;
		m /= n;
	}
	int size = v.size();
	for (int i = size - 1; i >= 0; --i)
	{
		retValue += v[i] * pow(10, i);
	}
	if (flag)
		cout << "-" << retValue << endl;
	else
		cout << retValue << endl;
	system("pause");
	return 0;
}