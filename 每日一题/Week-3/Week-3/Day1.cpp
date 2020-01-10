//1.参数解析
#if 0
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void Parse(string& s)
{
	vector<string> vs;
	string temp;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '"')
		{
			while (s[++i] != '"')
				temp += s[i];
			vs.push_back(temp);
			temp.clear();
			continue;
		}
		else if (s[i] == ' ')
		{
			vs.push_back(temp);
			temp.clear();
		}
		else
			temp += s[i];
	}
	if (!temp.empty())
		vs.push_back(temp);
	cout << vs.size() << endl;
	auto it = vs.begin();
	while (it != vs.end())
	{
		cout << *it << endl;
		it++;
	}
}
int main()
{
	string s;
	while (getline(cin, s))
		Parse(s);
	return 0;
}

#include<iostream>
#include<string>
#include<vector>
using namespace std;
void QueryParser(string& query)
{
	vector<string> token;
	for (int i = 0; i < query.size(); ++i)
	{
		string temp;
		//处理非“”类型的
		if (query[i] != ' ' && query[i]!='"')
			while (i<query.size() && query[i] != ' ')
				temp += query[i++];
		//处理“”类型的
		else if (query[i] == '"')
		{
			auto pos = query.find('"',i+1);
			temp = query.substr(i+1,pos);
			i = pos;
		}
		if (temp != "")
			token.push_back(temp);
	}
	cout << token.size() << endl;
	auto it = token.begin();
	while (it != token.end())
		cout << *it++ << endl;
}
int main()
{
	string query;
	while (getline(cin, query))
		QueryParser(query);
	return 0;
}


//2.跳石板







#endif