////#include <iostream>
////#include <algorithm>
////using namespace std;
////
////const int N = 5;
////int Money[4] = { 5, 2, 5, 2 };
////int Value[N] = { 1, 5, 10, 50, 100 };
////
////int solve(int money){
////	int num = 0;
////	for (int i = N - 1; i>=0; i--){
////		//c为使用纸币的张数，在需要用面值为vaule[i]的张数和已有张数里选取最小的；
////		int c = min(money / Value[i], Money[i]);
////		money = money - Value[i] * c;
////		num += c;
////	}
////	if (money>0){
////		num = -1;
////	}
////	return num;
////}
////int main(){
////	int money;
////	while (true)
////	{
////		cin >> money;//输入一共需要支付多少钱
////		int res = solve(money);
////		if (res != -1){
////			cout << res << endl;
////		}
////		else{
////			cout << "no" << endl;
////		}
////	}
////	
////	system("pause");
////	return 0;
////
////}
//
//
//
////#include<iostream>
////using namespace std;
////
////int mian()
////{
////
////}
//
////#include<iostream>  
////#include<algorithm>  
////using namespace std;
////
////#define N 7
////
////int Value[N] = { 1, 2, 5, 10, 20, 50, 100 };//该数组为不同种类币值
////int Count[N] = { 3, 5, 2, 1, 0, 3, 5 };//各种币值所拥有的个数
////int solve(int money)
////{
////	int num = 0;
////	for (int i = N - 1; i >= 0; i--)
////		//此处N-1相当于size-1，数组长度减一相当于i为数组最后一个元素下标，也就是优先取币值最大的纸币
////	{
////		int c = min(money / Value[i], Count[i]);//c为所取的币值个数
////		money = money - c * Value[i];
////		num += c;
////	}
////	if (money > 0)
////		num = -1;
////
////	return num;
////}
////
////int main()
////{
////	int money;
////	cin >> money;
////
////	int res = solve(money);
////
////	if (res != -1)
////		cout << res << endl;
////	else
////		cout << "NO" << endl;
////
////
////	system("pause");
////	return 0;
////}
//
//
//#include<iostream>
//using namespace std;
//
//#define N 5
//
//int SolveMoney(int k)
//{
//	int Value[N] = { 1, 5, 10, 50, 100 };
//	int ret = 0;
//	for (int i = N - 1; i >= 0; --i)
//	{
//		int c = k / Value[i];
//		k = k - c * Value[i];
//		ret += c;
//	}
//	return ret;
//}
//int main()
//{
//	int k = 0;
//	cin >> k;
//	int ret = SolveMoney(k);
//	if (ret != -1)
//		cout << ret << endl;
//	else
//		cout << "NO" << endl;
//
//	system("pause");
//
//	return 0;
//}

#include<iostream>
using namespace std;

