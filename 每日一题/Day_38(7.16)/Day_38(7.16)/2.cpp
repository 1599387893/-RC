

//ÊäÈë
//i am a student
//i  am   a      student
//i@am###a   student
//Êä³ö
//student a am i
//student a am i
//student a am i


#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		string rev;
		int start = s.size();
		int end = start - 1;
		for (; end >= 0; --end)
		{
			if ((!((s[end] >= 'A' && s[end] <= 'Z') || (s[end] >= 'a' && s[end] <= 'z'))) &&
				(!((s[end + 1] >= 'A' && s[end + 1] <= 'Z') || (s[end + 1] >= 'a' && s[end + 1] <= 'z'))))
			{
				start = end;
				continue;
			}
			if (!((s[end] >= 'A' && s[end] <= 'Z') || (s[end] >= 'a' && s[end] <= 'z')))
			{
				rev.append(s.begin() + end + 1, s.begin() + start);
				rev += ' ';
				start = end;
			}
		}
		rev.append(s.begin(), s.begin() + start);
		cout << rev << endl;
	}
	return 0;
}