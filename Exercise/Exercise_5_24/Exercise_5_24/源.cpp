////#include<iostream>
////#include<string>
////#include<algorithm>
////using namespace std;
////
////int main()
////{
////	string A;
////	string B;
////	int count = 0;
////	cin >> A >> B;
////
////	for (size_t i = 0; i <= A.size(); ++i)
////	{
////		string temp1(A);
////		if (i == 0)
////			temp1 = B + A;
////		else
////			temp1 = A.substr(0, i) + B + A.substr(i);
////
////		//�ж�
////		string temp2(temp1);
////		reverse(temp2.begin(), temp2.end());
////		if (temp2 == temp1)
////		{
////			++count;
////		}
////	}
////	cout << count << endl;
////	system("pause");
////	return 0;
////}
//
////#include<iostream>
////#include<vector>
////using namespace std;
////
////int main()
////{
////	int n = 0;
////	cin >> n;
////	
////	if (n<1 || n>100000)
////		return 0;
////	vector<int>v;
////	v.resize(n);
////	for (size_t i = 0; i<n; ++i)
////		cin >> v[i];
////
////	int ret = v[0];
////	int de
////	for (size_t i = 0; i < n; ++i)
////	{
////		if ()
////	}
////	cout << ret << endl;
////
////	system("pause");
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int main(void)
//{
//	int n, max;
//	cin >> n;
//	vector<int> list(n, 0), dp(list);
//	for (int i = 0; i < n; i++)   //��������
//		cin >> list[i];
//
//	max = dp[0] = list[0];
//	for (int i = 1; i < n; i++)   //�����������ģ����ֻ��Ҫ���¶�
//	{                                     //���߼��ɣ�֮ǰ��������һ����ͬ
//		if (list[i] + dp[i - 1] > list[i])      //�����һ�Խ����ϵ����͸���
//			dp[i] = list[i] + dp[i - 1];       //�����Ӧλ��
//		else
//			dp[i] = list[i];                       //���򣬼�Ϊ���������
//		if (max < dp[i]) max = dp[i];     //Ѱ������������
//
//	}
//	cout << max << endl;
//	return 0;
//}

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int>v;
	v.resize(n);
	int sumMax = 0;
	int temp = 0;
	for (size_t i = 1; i < n; ++i)
	{
		temp += v[i];
		if (temp + v[i] > 0)
			sumMax += v[i];
		else

	}
}