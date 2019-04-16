////找出字符串中第一个只出现一次的字符
//#include<iostream>
//#include<string>
//using namespace std;
//
//
//int main()
//{
//	string str;
//	getline(cin, str); 
//	size_t size = str.size();
//	int arr[256] = { 1 };
//	size_t i = 0;
//	for (i = 0; i < size; i++)
//		arr[str[i]]++;
//
//	for (i = 0; i < size; i++)
//		if (1 == arr[str[i]])
//			cout << str[i] << endl;
//	if (i == size)
//		cout << -1 << endl;
//
//	system("pause");
//	return 0;
//}

//
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s;
//	cin >> s;
//	char* begin = string::iterator(s.begin());
//
//	cout << begin + 2 << endl;
//
//	system("pause");
//
//	return 0;
//}

#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	string str1 = "hello world";
	string str2 = str1;

	printf("Sharing the memory:/n");
	printf("/tstr1's address: %x/n", str1.c_str());
	printf("/tstr2's address: %x/n", str2.c_str());

	str1[1] = 'q';
	str2[1] = 'w';

	printf("After Copy-On-Write:/n");
	printf("/tstr1's address: %x/n", str1.c_str());
	printf("/tstr2's address: %x/n", str2.c_str());

	return 0;
}