#if 0
#include<iostream>
using namespace std;
int main(){
	long long arr[80] = { 1, 1 };
	for (int i = 2; i<80; i++){
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int from = 0, to = 0;

	while (cin >> from >> to){
		long long res = 0;
		for (int i = from; i <= to; i++){
			res = res + arr[i - 1];
		}
		cout << res << endl;
	}
	return 0;
}

//// write your code here cpp
//#include<iostream>
//using namespace std;
//
//int count_breakfast(int from, int to)
//{
//	int f1 = 1;
//	int f2 = 1;
//	int ret = 0;
//	if (from == 1 || from == 2)
//		ret = 1;
//	//ret = f2;//先加上from这天的人数
//	for (int i = 1; i<to; ++i)
//	{
//		int temp = f1 + f2;
//		f1 = f2;
//		if (i >= from-1)
//			ret += f2;
//		f2 = temp;
//
//	}
//	return ret;
//}
//int main()
//{
//	int from = 0;
//	int to = 0;
//	while (cin >> from >> to)
//	{
//		if (from<1 || from>80 || to<1 || to>80)
//			continue;
//		else
//			cout << count_breakfast(from, to) << endl;
//	}
//	return 0;
//}
#endif