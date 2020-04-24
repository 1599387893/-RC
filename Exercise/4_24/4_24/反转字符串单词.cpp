#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

void ReverseWord1(string& str)
{
	reverse(str.begin(), str.end());
	auto begin = str.begin();
	auto end = str.begin();
	while (end != str.end())
	{
		if (*end == ' ')
		{
			reverse(begin, end);
			begin = end + 1;
		}
		end++;
	}
	if (begin != end)
		reverse(begin, end);
}

void ReverseWord2(string& str)
{
	string res;
	queue<char> q;
	for (auto c : str)
	{
		if (c != ' ')
			q.push(c);
		else
		{
			string temp;
			while (!q.empty())
			{
				temp.push_back(q.front());
				q.pop();
			}
			temp.push_back(' ');
			res.insert(res.begin(), temp.begin(), temp.end());
		}
	}
	if (!q.empty())
	{
		string temp;
		while (!q.empty())
		{
			temp.push_back(q.front());
			q.pop();
		}
		temp.push_back(' ');
		res.insert(res.begin(), temp.begin(), temp.end());
	}
	str = res;
}
void Reverse(string& str)
{
	/*
	int left = 0, right = str.size()-1;
	while (left < right)
		swap(str[left++], str[right--]);
	*/
	stack<char> temp;
	for (const auto& c : str)
		temp.push(c);
	for (int i = 0; i < str.size(); ++i,temp.pop())
		str[i] = temp.top();
}

int main()
{
	string str;
	getline(cin, str);
	//ReverseWord1(str);
	//ReverseWord2(str);
	//ReverseWord3(str);
	Reverse(str);
	cout << str << endl;
	cin >> str;
	return 0;
}