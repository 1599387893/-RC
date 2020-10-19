#include <iostream>
#include <stack>
#include <string>
using namespace std;

//1.�Ƚ���׺���ʽת��Ϊ��׺���ʽ(�沨�����ʽ)
//2.����ջ�����׺���ʽ
//����ֻ����+��*

int GetNum(const string& str, int& pos)
{
	int res = 0;
	bool nega = false;
	if (str[pos] == '-')
	{
		nega = true;
		pos++;
	}
	while (pos < str.size() && isdigit(str[pos]))
	{
		res = res * 10 + str[pos] - '0';
		pos++;
	}
	return nega ? 0 - res : res;
}

//���������ȼ�
string op_level{"+*"};
int Level(char& c)
{
	for (int i = 0; i < op_level.size(); ++i)
		if (op_level[i] == c)
			return i;
	return -1;
}
//����׺���ʽת���ɺ�׺���ʽ���������ţ�
string InfixToSuffix(string& str)
{
	string res;
	stack<char> sop; //������ջ
	stack<int> val; //������ջ(ʹ��boolȷ����Ԫ���Ƿ�Ϊ����)
	int pos = 0;
	int size = (int)str.size();
	while (pos < size)
	{
		if (isdigit(str[pos]) || str[pos] == '-')
		{
			res += str[pos++];
		}
		if (pos < size && (str[pos] == '+' || str[pos] == '*' || str[pos] == '('))
		{
			//���ڲ�����ջ�Ĳ������ 
			//    1.���sopջջ���Ĳ����������ȼ� > ��Ҫ����Ĳ����������ȼ�  -----> ֱ����ջ
			//    2.���sopջջ���Ĳ����������ȼ� <=  ��Ҫ����Ĳ����������ȼ�  ----> һֱ����ջ��Ԫ�ز����뵽��׺���ʽ�У�ֱ����������1
			if (sop.empty() || (Level(sop.top()) > Level(str[pos])) || str[pos] == '(')
			{
				sop.push(str[pos]);
			}
			else  //��ǰsopջջ����Ԫ�ص����ȼ� > ��Ҫ�����Ԫ�ص����ȼ�
			{
				while (!sop.empty() && (Level(sop.top()) < Level(str[pos])))
				{
					res += sop.top();
					sop.pop();
				}
				sop.push(str[pos]);
			}
			pos++;
		}
		if (pos < size && str[pos] == ')')  //���������
		{
			while (!sop.empty() && sop.top() != '(')
			{
				res += sop.top();
				sop.pop();
			}
			sop.pop(); //����ƥ���������
		}
	}
	//����ջ�е�Ԫ��
	while (!sop.empty())
	{
		res += sop.top();
		sop.pop();
	}
	return res;
}
int Calc(string& str)
{
	//����׺���ʽת���ɺ�׺���ʽ
	string suf = InfixToSuffix(str);
	//�������׺���ʽ�Ľ��
}
int main()
{
	string str;
	getline(cin, str);
	cout << str << " = " << Calc(str) << endl;
	return 0;
}