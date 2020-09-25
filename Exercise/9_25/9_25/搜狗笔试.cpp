#if 0
class Solution {
public:
	/**
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	* ����һ���ַ�������ʾԭ�ġ�
	* @param s1 string�ַ���vector N*N��01���󣬱�ʾ����ֽ��0��ʾ͸����1��ʾͿ��
	* @param s2 string�ַ���vector �ַ����󣬱�ʾ����
	* @return string�ַ���
	*/
	string getText(vector<string>& s1, vector<string>& s2)
	{
		string ret;
		for (int i = 0; i < (int)s1.size(); ++i)
			for (int j = 0; j < (int)s1[i].size(); ++j)
				if (s1[i][j] == '0')
					ret += s2[i][j];
		return ret;
	}
	void Rotate(vector<string>& s)
	{
		int pos = 0;
		int size = (int)s.size();
		while (pos < size / 2)
		{
			for (int col = pos; col < size - 1 - pos; ++col)
			{
				char n = s[pos][col];
				swap(n, s[col][size - 1 - pos]);
				swap(n, s[size - 1 - pos][size - 1 - col]);
				swap(n, s[size - 1 - pos][col]);
				swap(n, s[pos][col]);
			}
			pos++;
		}
	}
	string rotatePassword(vector<string>& s1, vector<string>& s2) {
		// write code here
		if (s1.empty() || s2.empty()) return "";
		string res;
		for (int i = 0; i < 4; ++i)
		{
			res += getText(s1, s2);
			Rotate(s1);
		}
		return res;
	}
};



class Solution {
public:
	/**
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	* ����һ���ַ�������ʾԭ�ġ�
	* @param s1 string�ַ���vector N*N��01���󣬱�ʾ����ֽ��0��ʾ͸����1��ʾͿ��
	* @param s2 string�ַ���vector �ַ����󣬱�ʾ����
	* @return string�ַ���
	*/
	string getText(vector<string>& s1, vector<string>& s2)
	{
		string ret;
		for (int i = 0; i < (int)s1.size(); ++i)
			for (int j = 0; j < (int)s1[i].size(); ++j)
				if (s1[i][j] == '0')
					ret += s2[i][j];
		return ret;
	}
	void Rotate(vector<string>& s)
	{
		vector<string> temp(s);
		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = 0; j < (int)s.size(); ++j)
			{
				temp[i][j] = s[s.size() - j - 1][i];
			}
		}

		s = temp;
	}
	string rotatePassword(vector<string>& s1, vector<string>& s2) {
		// write code here
		if (s1.empty() || s2.empty()) return "";
		string res;
		for (int i = 0; i < 4; ++i)
		{
			res += getText(s1, s2);
			Rotate(s1);
		}
		return res;
	}
};
#endif



#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstring>
using namespace std;


struct Interval {
	int start;
	int end;
};

set<int> res;
void Find(vector<Interval>& conn, vector<int> cur, int pos)
{
	for (auto in : conn)
	{
		if (in.start == pos)
		{
			if (in.end == -1)
			{
				for (auto n : cur)
					res.insert(n);
			}
			else
			{
				cur.push_back(in.end);
				Find(conn, cur, in.end);
				cur.pop_back();
			}
		}
	}
}
Interval trim(int N, int M, vector<Interval>& conn) {
	vector<int> cur;
	Find(conn, cur, 0);
	int sum = 0;
	for (auto it = res.begin(); it != res.end(); ++it)
		sum += *it;
	Interval ret;
	ret.start = res.size();
	ret.end = sum;
	return ret;
}
int main()
{
	char* str = (char*)malloc(100000000 * 10000000000);
	vector<Interval> con{ {0,1}, {0,2}, {2,-1}, {2,1} };

	trim(3,4,con);
}