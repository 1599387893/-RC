//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<int> vec;
//	int n, i;
//	cout << "���������ԲȦ�����ָ�����";
//	cin >> n;
//	for (i = 1; i <= n; ++i)
//	{
//		vec.push_back(i);
//	}	
//	i = 0;
//	while (!vec.empty())
//	{
//		i = i % vec.size();
//		cout << vec.at(i) << ends;
//		vec.erase(vec.begin() + i);
//		i += 2;
//	}
//	system("pause");
//	return 0;
//}
//	

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	char c;
	string op_left = "([{";
	string op_right = ")]}";
	stack<char> s;

	while ((c = getchar()) != '\n')
	{
		if (op_left.find(c) < op_left.length())
			s.push(c);
		else if (op_right.find(c) < op_right.length())
			if (s.size() == 0 || op_right.find(c) != op_left.find(s.top()))
			{
				cout << "��ƥ��" << endl;
				break;		//���ҵ������ţ�ȴû����Ӧ������ƥ�䣬�˳�ѭ��
			}	
		else
			s.pop();	//������Ӧ�����ų�ջ
	}
	if (s.size() > 0)		//������������δ��ƥ�䣬��˵����ƥ��
		cout << "��ƥ��" << endl;
	else
		cout << "ƥ��" << endl;
	system("pause");
	return 0;
}