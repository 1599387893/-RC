//#include<iostream>
//#include<string>
//#include<math.h>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	int len1, len2;
//	while (cin >> s1 >> s2 >> len1 >> len2)
//	{
//		int count = 0;
//		if (len2>s2.size())
//			len2 = s2.size();
//		for (int i = len1; i <= len2; ++i)
//		{
//			if (s2[i - 1]>s1[i - 1])
//				count += s2[i - 1] - s1[i - 1] ;
//			int n = 0;
//			for (int j = i; j > 0; --j)
//				count += pow(26, n++)*s2[j - 1] - s1[j - 1];
//		}
//		cout << count << endl;
//	}
//	return 0;
//}

// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	string ret;
	while (cin >> s1 >> s2)
	{
		if (s1.size()>s2.size())
			s1.swap(s2);
		int size = s1.size();
		int sit = 0;
		int flag = -1;
		for (int i = 0; i<size; ++i)
		{
			if (flag==-1)
				sit = s2.find(s1[i], i);
			else
				sit = s2.find(s1[i],flag);
			if (sit != -1 && flag <= sit)
			{
				flag = sit;
				ret.push_back(s1[i]);
			}
		}
		cout << ret.size() << endl;
		ret.clear();
	}
	return 0;
}