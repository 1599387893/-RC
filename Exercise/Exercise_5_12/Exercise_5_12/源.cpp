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
////		//cΪʹ��ֽ�ҵ�����������Ҫ����ֵΪvaule[i]������������������ѡȡ��С�ģ�
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
////		cin >> money;//����һ����Ҫ֧������Ǯ
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
////int Value[N] = { 1, 2, 5, 10, 20, 50, 100 };//������Ϊ��ͬ�����ֵ
////int Count[N] = { 3, 5, 2, 1, 0, 3, 5 };//���ֱ�ֵ��ӵ�еĸ���
////int solve(int money)
////{
////	int num = 0;
////	for (int i = N - 1; i >= 0; i--)
////		//�˴�N-1�൱��size-1�����鳤�ȼ�һ�൱��iΪ�������һ��Ԫ���±꣬Ҳ��������ȡ��ֵ����ֽ��
////	{
////		int c = min(money / Value[i], Count[i]);//cΪ��ȡ�ı�ֵ����
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

