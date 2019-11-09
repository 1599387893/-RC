//#include<iostream>
//#include<string>
//using namespace std;
//
//string Reverse(string s)
//{
//	string ret;
//	int size = 0;
//	for (int i = s.size() - 1; i >= 0; --i)
//	{
//		if (s[i] == ' ' || i == 0)
//		{
//			ret += s.substr(i+1, size+1);
//			ret += ' ';
//			size = 1;
//		}
//		else
//			size++;
//	}
//	return ret;
//}
//int main()
//{
//	string s;
//	while (getline(cin,s))
//		cout << Reverse(s) << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//long long MaxLevel(vector<long>& v,int n)
//{
//	sort(v.begin(), v.end());
//	long long ret = 0;
//	for (int i = v.size() - 2; n>0; i-=2,n--)
//		ret += v[i];
//	return ret;
//}
//int main()
//{
//	long long n;
//	while (cin >> n)
//	{
//		vector<long> v(3 * n);
//		for (int i = 0; i < n * 3; ++i)
//			cin >> v[i];
//		cout << MaxLevel(v,n) << endl;
//	}
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//
//void Erase(string& s1, string&s2)
//{
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		if (s2.find(s1[i]) != string::npos)
//		{
//			s1.erase(s1.begin() + i);
//			i--;
//		}
//	}
//}
//int main()
//{
//	string s1;
//	string s2;
//	while (getline(cin, s1))
//	{
//		getline(cin, s2);
//		Erase(s1, s2);
//		cout << s1 << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//string Erase(string& s1, string&s2)
//{
//	string ret;
//	for (size_t i = 0; i<s1.size(); ++i)
//	{
//		if (s2.find(s1[i]) == string::npos)
//			ret += s1[i];
//	}
//	return ret;
//}
//int main()
//{
//	string s1;
//	string s2;
//	while (getline(cin, s1))
//	{
//		getline(cin, s2);
//		cout << Erase(s1, s2) << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	/*string s = "This is Test";
//	printf("%10.3s\n", s.c_str());*/
//	cout << sizeof(int) << endl;
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<string>
using namespace std;

void Reserve(string& s)
{
	reverse(s.begin(),s.end());
	auto it = s.begin();
	auto start = it;
	while (it != s.end())
	{
		if (*it == ' ')
		{
			reverse(start,it);
			start = ++it;
		}
		else
			it++;
	}
	reverse(start, it);
}
int main()
{
	string s1;
	string s2;
	while (getline(cin, s1))
	{
		Reserve(s1);
		cout << s1 << endl;
	}
	system("pause");
	return 0;
}