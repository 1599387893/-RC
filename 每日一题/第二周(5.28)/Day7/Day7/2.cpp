//2
//合法括号序列判断（括号是否匹配）
//输入示例：
//			（）（）（） 6
//			（（）） 4
//			（）（（（） 6
//输出示例：
//			true
//			true
//			false

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> sc;
		for (auto ele : A) {
			switch (ele) {
			case '(':
				sc.push(ele);
				break;
			case ')':
			{
				if (sc.empty() || sc.top() != '(')
					return false;
				else
					sc.pop();
			}
				break;
			default:
				return false;
			}
		}
		return true;
	}
};
int main()
{
	Parenthesis p;
	int n = 0;
	string s;
	getline(cin, s);
	cin >> n;
	cout << p.chkParenthesis(s, n) << endl;

	system("pause");
	return 0;
}


#include<iostream>
#include<string>
using namespace std;

bool chkParenthesis(string A, int n) 
{
	if (n % 2 == 1)
		return false;
	string s = "";
	for (int i = 0; i < A.size(); ++i)
	{
		if ((s.size()>0 && s[s.size() - 1] == '(' && A[i] == ')') || (s.size()>0 && s[s.size() - 1] == ')' && A[i] == '('))
			s.resize(s.size() - 1);
		else
			s.push_back(A[i]);
	}
	if (s.size() == 0)
		return true;
	return false;
}

int main()
{
	string a = "()()()(";
	int n;
	//getline(cin, a);
	//cin >> n;
	cout << chkParenthesis(a, 6);
	system("pause");
	return 0;
