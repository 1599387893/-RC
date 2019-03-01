//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<int> vec;
//	int n, i;
//	cout << "请输入组成圆圈的数字个数：";
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
				cout << "不匹配" << endl;
				break;		//若找到右括号，却没有相应左括号匹配，退出循环
			}	
		else
			s.pop();	//否则相应左括号出栈
	}
	if (s.size() > 0)		//若还有左括号未被匹配，则说明不匹配
		cout << "不匹配" << endl;
	else
		cout << "匹配" << endl;
	system("pause");
	return 0;
}