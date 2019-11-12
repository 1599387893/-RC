//1.统计回文
#if 0
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool Roll(string& temp)
{
	stack<char> s;
	int i = 0;
	for (i = 0; i < temp.size() / 2; ++i)
		s.push(temp[i]);
	if (temp.size() % 2 != 0)
		i++;
	for (; i < temp.size(); ++i)
		if (s.top() == temp[i])
			s.pop();
	return s.size() == 0 ? true : false;

}
int Count(string& s1, string& s2)
{
	int count = 0;
	string temp;
	int size = s1.size();
	for (int i = 0; i <= size; ++i)
	{
		temp = s1.substr(0, i) + s2 + s1.substr(i, i + size);
		if (Roll(temp))
			count++;
	}
	return count;
}
int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
		cout << Count(s1, s2) << endl;
	return 0;
}
//#endif
//2.连续最大和

#include<iostream>
#include<vector>
using namespace std;

int MaxAdd(vector<int>& v)
{
	if (v.size() == 0)
		return 0;
	if (v.size() == 1)
		return v[1];
	int sum = 0, maxsum = -100000000;
	for (size_t i = 0; i < v.size(); ++i)
	{
		sum += v[i];
		if (sum > maxsum)
			maxsum = sum;
		if (sum < 0)
			sum = 0;
	}
	return maxsum;
}

int main()
{
	int n;
	vector<int> v;
	while (cin >> n)
	{
		int temp;
		for (int i = 0; i<n; ++i)
		{
			cin >> temp;
			v.push_back(temp);
		}
		cout << MaxAdd(v) << endl;
		v.clear();
	}
	return 0;
}
#endif
//--------------------------------------------------------------------------------------------------------------------
//高效解法
//1.
#if 0
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int CountRoll(string& s1, string& s2)
{
	int count = 0;
	string temp1;
	string temp2;
	for (int i = 0; i < s1.size(); ++i)
	{
		temp1 = s1.substr(0, i) + s2 + s1.substr(i);
		temp2 = temp1;
		reverse(temp1.begin() ,temp1.end());
		if (temp1 ==  temp2)
			count++;
	}
	return count;
}
void Test1()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
		cout << CountRoll(s1, s2) << endl;
}
//2.
void Test2()
{
	int n;
	while (cin >> n)
	{
		int sum = 0;
		int maxsum = -100000000;
		int temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			sum += temp;
			if (sum > maxsum)
				maxsum = sum;
			if (sum < 0)
				sum = 0;
		}
		cout << maxsum << endl;
	}
}
int main()
{
	//Test1();
	Test2();
	return 0;
}
#endif