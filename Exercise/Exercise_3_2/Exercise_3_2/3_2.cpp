//#include<iostream>
//#include<queue>
//#include<iomanip>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cout << "请输入杨辉三角的层数(^z结束)：";
//	while (cin >> n)
//	{
//		queue<int> q;
//		for (int i = 0; i <= n - 1; ++i)
//		{
//			for (int j = 0; j < n - i - 1; ++j)
//			{
//				cout << "   ";
//			}
//			if (i > 0)
//			{
//				q.push(1);
//				cout << setw(3) << 1 << "   ";
//			}
//			if (i > 1)
//			{
//				q.pop();
//				for (int j = 1; j < i; ++j)
//				{
//					int num = q.front();
//					q.pop();
//					num += q.front();
//					q.push(num);
//					cout << setw(3) << num << "   ";
//				}
//			}
//			q.push(1);
//			cout << setw(3) << 1 << endl;
//		}
//		cout << endl;
//		cout << "请输入杨辉三角的层数(^z结束)：";
//	}
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;

int main(){
	int n;
	cout << "请输入三角形的层数(^Z结束)：";
	while (cin >> n)
	{
		queue<int> q;
		for (int i = 0; i <= n - 1; ++i)
		{
			for (int j = 0; j < n - i - 1; ++j)
			{
				cout << "   ";
			}
			if (i > 0)
			{
				q.push(1);
				cout << setw(3) << 1 << "   ";	//输出每行行首的1
			}
			if (i > 1)
			{
				q.pop();	//删除上一行行末的1
				for (int j = 1; j < i; ++j)
				{
					int num = q.front();
					q.pop();
					num += q.front();	//当前数等于队列中第1、2个元素之和，
					//即要保证队头为当前数左上方的数字
					q.push(num);
					cout << setw(3) << num << "   ";
				}
			}
			q.push(1);
			cout << setw(3) << 1 << endl;	//输出每行行末的1
		}
		cout << endl;
		cout << "请输入三角形的层数(^Z结束)：";
	}
	return 0;
}