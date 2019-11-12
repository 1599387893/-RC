//#include<iostream>
//#include<stack>
//using namespace std;
//
//int main()
//{
//	cout << (5 / 2) << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//
//bool Roll(string& temp)
//{
//	stack<char> s;
//	int i = 0;
//	for (i = 0; i < temp.size() / 2; ++i)
//		s.push(temp[i]);
//	if (temp.size() % 2 != 0)
//		i++;
//	for (; i < temp.size(); ++i)
//		if (s.top() == temp[i])
//			s.pop();
//	return s.size() == 0 ? true : false;
//
//}
//int Count(string& s1, string& s2)
//{
//	if (s1.size() == 0)
//	{
//		if (Roll(s2))
//			return 1;
//		else
//			return 0;
//	}
//	if (s2.size() == 0)
//	{
//		if (Roll(s1))
//			return 1;
//		else
//			return 0;
//	}
//
//	int count = 0;
//	string temp;
//	int size = s1.size();
//	for (int i = 0; i <= size; ++i)
//	{
//		temp = s1.substr(0, i) + s2 + s1.substr(i, i + size);
//		if (Roll(temp))
//			count++;
//	}
//	return count;
//}
//int main()
//{
//	string s1;
//	string s2;
//	while (cin >> s1 >> s2)
//		cout << Count(s1, s2) << endl;
//	return 0;
//}

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	while (cin >> n)
	{
		int temp;
		for (int i = 0; i<n; ++i)
		{
			v.push_back((cin >> temp));
		}
		v.clear();
	}
}