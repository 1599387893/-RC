//////#include<iostream>
//////using namespace std;
//////
//////int main()
//////{
//////	int a[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 }, *p;
//////	int i = 8;
//////	p = a + i;
//////	printf("%s\n", p-3);
//////	cout << typeid(p - 3).name() << endl;
//////	system("pause");
//////	return 0;
//////}
////#include<iostream>
////#include<vector>
////using namespace std;
////
////int main()
////{
////	vector<int> array;
////	int i = 0;
////	int n = 0;
////	while (cin >> n)
////	{
////		array.resize(i + 1);
////		array[i++] = n;
////
////	}
////	int size = array.size();
////	vector<int> hashTable;
////	hashTable.resize(size,1);
////
////	for (int i = 0; i<size; ++i)
////	{
////		for (int j = i + 1; j<size; ++j)
////			if (array[i] == array[j])
////				++hashTable[i];
////		if (hashTable[i] >= size / 2)
////		{
////			cout << array[i] << endl;
////			break;
////		}
////	}
////	return 0;
////
////}
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str;
//	cin >> str;
//
//	string::iterator retIt = str.begin();
//	string::iterator midIt = str.begin();
//	int retSize = 0;
//	int midSize = 0;
//	auto it = str.begin();
//
//	while (it != str.end())
//	{
//		if (*it >= '0' && *it <= '9')
//		{
//			if (*midIt <= '0' || *midIt >= '9')
//				midIt = it;
//			++midSize;
//		}
//		if ((midIt != retIt)&&(midSize > retSize))
//		{
//			retIt = midIt;
//			retSize = midSize;
//			midSize = 0;
//		}
//		++it;
//	}
//	if (midIt > retIt)
//	{
//		retIt = midIt;
//		retSize = midSize;
//	}
//	string ret(retIt, retIt + retSize);
//	cout << ret << endl;
//	return 0;
//}
#if 0
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;//定义str为某个要输入的字符串
	cin >> str;

	string tmp;//定义一个临时字符串数组用来存放数字串
	string maxstr;//只存放最长的数字串
	int maxlength = 0;

	for (int i = 0; i<str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			//次数的while循环和if中的判断语句一样，但是千万不可以少
			//while是为了将所有的数字串都加进tmp当中
			while (str[i] >= '0' && str[i] <= '9')
			{
				tmp += str[i++];
			}
			if (tmp.size()>maxlength)
			{
				maxstr = tmp;
				maxlength = tmp.size();
			}
		}
		tmp.clear();
	}
	cout << maxstr<<endl;
	system("pause");
	return 0;
}
#endif