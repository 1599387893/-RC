//#include<iostream>
//#include<queue>
//#include<iomanip>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cout << "������������ǵĲ���(^z����)��";
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
//		cout << "������������ǵĲ���(^z����)��";
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
	cout << "�����������εĲ���(^Z����)��";
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
				cout << setw(3) << 1 << "   ";	//���ÿ�����׵�1
			}
			if (i > 1)
			{
				q.pop();	//ɾ����һ����ĩ��1
				for (int j = 1; j < i; ++j)
				{
					int num = q.front();
					q.pop();
					num += q.front();	//��ǰ�����ڶ����е�1��2��Ԫ��֮�ͣ�
					//��Ҫ��֤��ͷΪ��ǰ�����Ϸ�������
					q.push(num);
					cout << setw(3) << num << "   ";
				}
			}
			q.push(1);
			cout << setw(3) << 1 << endl;	//���ÿ����ĩ��1
		}
		cout << endl;
		cout << "�����������εĲ���(^Z����)��";
	}
	return 0;
}