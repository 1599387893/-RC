////////#include<iostream>
////////#include<string>
////////using namespace std;
////////
////////int main()
////////{
////////	string s;
////////	getline(cin, s);
////////	
////////	cout << s << endl;
////////	system("pause");
////////	return 0;
////////}
//////
//////#include<iostream>
//////#include<string>
//////using namespace std;
//////
//////int main()
//////{
//////	string s;
//////	getline(cin, s);
//////	string retS;
//////
//////	int size = s.size();
//////	//retS.reserve(size);
//////	retS.reserve(size);
//////	for (int i = 0, j = size - 1; i<size; ++i, --j)
//////		retS[i] = s[j];
//////
//////	cout << retS << endl;
//////
//////	return 0;
//////}
////
////#include<iostream>
////#include<string>
////#include<stack>
////using namespace std;
////
////int main()
////{
////	string str;
////	getline(cin, str);
////	//stack<char> s;
////
////	int size = str.size();
////	for (int i = 0; i < size/2; ++i)
////		//s.push(str[i]);
////		swap(str[i], str[size - i - 1]);
////
////	cout << str << endl;
////	system("pause");
////	return 0;
////}
//////
//////#include<iostream>
//////#include<string>
//////#include<stack>
//////using namespace std;
//////
//////int main()
//////{
//////	string str;
//////	getline(cin, str);
//////	stack<char> s;
//////
//////	int size = str.size();
//////	for (int i = 0; i < size; ++i)
//////		s.push(str[i]);
//////	for (int i = 0; i < size; ++i)
//////	{
//////		str[i] = s.top();
//////		s.pop();
//////	}
//////	cout << str << endl;
//////	return 0;
//////}
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	while (cin >> v)
//	{
//
//	}
//}