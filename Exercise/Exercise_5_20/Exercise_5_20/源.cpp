////#include<iostream>
////using namespace std;
////
////int midLevel(int* level, int i)
////{
////	if ((level[i] >= level[i + 1] && level[i] <= level[i + 2]) || (level[i]<=level[i + 1] && level[i]>=level[i + 2]))
////		return level[i];
////	if ((level[i+1] >= level[i] && level[i+1] <= level[i + 2]) || (level[i+1] <= level[i] && level[i+1] >= level[i + 2]))
////		return level[i+1];
////	if ((level[i+2] >= level[i + 1] && level[i+2] <= level[i]) || (level[i+2] <= level[i + 1] && level[i+2] >= level[i]))
////		return level[i+2];
////
////}
////int GetMaxLevel(int* level, int num)
////{
////	int retSum = 0;
////	for (int i = 0; i < num; i += 3)
////	{
////		retSum += midLevel(level, i);
////	}
////	return retSum;
////}
////int main()
////{
////	int n = 0;
////	cin >> n;
////	int* level = new int[3 * n];
////	int i = 0;
////
////	while (i < (3 * n))
////		cin >> level[i++];
////	
////	int MaxLevelSum = GetMaxLevel(level, 3 * n);
////	cout << MaxLevelSum << endl;
////	delete[] level;
////	system("pause");
////	return 0;
////}
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//
//int main()
//{
//	string s1;
//	string s2;
//	string retS;
//	getline(cin, s1);
//	getline(cin, s2);
//
//	int size2 = s2.size();
//	for (int i = 0; i < (int)s1.size(); ++i)
//	{
//		for (int j = 0; s1[i]!=' '&& j < size2; ++j)
//			if (s1[i] == s2[j])
//				s1.erase(i,1);
//	}
//	
//	cout << s1 << endl;
//
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char s[] = "coumpter";
//	printf("%5.3s\n", s);
//	system("pause");
//	return 0;
//}
#include<iostream>
using namespace std;
//
//int main()
//{
//	int a = 1;
//	float b = 1.34;
//	cout << typeid(b + 'A' + a).name() << endl;
//	system("pause");
//	return 0;
//}
//int main()
//{
//	cout << (11 | 10) << endl;
//	system("pause");
//	return 0;
//}