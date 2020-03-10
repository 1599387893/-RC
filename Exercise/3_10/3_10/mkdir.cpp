//// write your code here cpp
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<string> arr(n);
//		for (int i = 0; i < n; ++i)
//			cin >> arr[i];
//		sort(arr.begin(), arr.end());
//		for (int i = 0; i < n-1; ++i)
//		{
//			int j = i + 1;
//			while (j<n)
//			{
//				auto pos = arr[j].find(arr[i]);
//				if ((pos != string::npos) && (pos == 0))
//					j++;
//				else
//					break;
//			}
//			if (j == i + 1)
//				cout << "mkdir -p " << arr[i] << endl;
//		}
//		cout<<"mkdir -p "<<arr[n-1]<<endl;
//		cout << endl;
//	}
//	return 0;
//}


// write your code here cpp
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		set<string> arr;//用来保存输入
		string temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			arr.insert(temp);
		}
		for (auto it = arr.begin(); it != --arr.end(); ++it)
		{
			auto j = it++;
			auto pos = (*it).find((*j));
			if ((pos == string::npos) || (pos != 0) || (*it)[(*j).size()] != '\/')//判断是不是后边这个串的子串，并且开始位置相同，满足条件不用输出
				cout << "mkdir -p " << *j << endl;
			it = j;
		}
		cout << "mkdir -p " << *(--arr.end()) << endl;//无论何种情况最后一个一定会出输出
		cout << endl;
	}
	return 0;
}