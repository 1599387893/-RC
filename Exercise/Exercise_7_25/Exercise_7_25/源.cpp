//// write your code here cpp
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	int maxSize = 0;
//	while (cin >> n)
//	{
//		vector<int> v;
//		int x;
//		while (n--)
//		{
//			cin >> x;
//			v.push_back(x);
//		}
//		for (size_t i = 0; i<v.size() - 1; ++i)
//		{
//			int size = 1;
//			int temp = v[i];
//			for (size_t j = i + 1; j<v.size(); ++j)
//			{
//				if (v[j]>temp)
//				{
//					temp = v[j];
//					size++;
//				}
//			}
//			if (size>maxSize)
//				maxSize = size;
//		}
//		cout << maxSize << endl;
//	}
//	return 0;
//}

// write your code here cpp
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	int maxSize = 0;
//	while (cin >> n)
//	{
//		if (n == 1)
//		{
//			cout << 1 << endl;
//			continue;
//		}
//		vector<int> v;
//		int x;
//		while (n--)
//		{
//			cin >> x;
//			v.push_back(x);
//		}
//		for (size_t i = v.size() - 1; i>0; --i)
//		{
//			int size = 1;
//			int temp = v[i];
//			for (int j = i - 1; j >= 0; --j)
//			{
//				if (v[j]<temp)
//				{
//					temp = v[j];
//					size++;
//				}
//			}
//			if (size>maxSize)
//				maxSize = size;
//		}
//		cout << maxSize << endl;
//	}
//	return 0;
//}



//#include <iostream>
//#include <vector>
//#include<algorithm>
//using namespace std;
//int main(){
//	int n;
//	while (cin >> n){
//		vector<int> height(n, 0);
//		for (int i = 0; i < n; i++){
//			cin >> height[i];
//		}
//
//		vector<int> f(n, 1);
//		int result = 1;
//		for (int i = 1; i < n; i++){
//			for (int j = 0; j < i; j++){
//				if (height[i] > height[j]){
//					f[i] = max(f[i], f[j] + 1);
//				}
//			}
//			result = max(result, f[i]);
//		}
//
//		cout << result << endl;
//	}
//}

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main(void)
{
	long long der[21] = { 0, 0, 1 };
	int i;
	for (i = 3; i < 21; i++){
		der[i] = (i - 1) * (der[i - 2] + der[i - 1]);
	}

	int n;
	while (scanf("%d", &n) != EOF){
		printf("%lld\n", der[n]);
	}
	return 0;
}
