#include<iostream>
#include<string>
#include<vector>
using namespace std;
#if 0
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
			temp = query.substr(i+1,pos-i+1);
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
#endif
//#if 0
void QueryParser(string& query)
{
	vector<string> token;
	int i = 0;
	for (i = 0; i < query.size(); ++i)
	{
		string temp;
		auto pos = query.find('"',i);
		auto spos = query.find(' ',i);
		if (pos != std::string::npos && spos != std::string::npos)
		{
			if (pos > spos)
			{
				temp = query.substr(i,spos-i);
				i = spos+1;
			}
			else
			{
				if (pos == 0)
					continue;
				temp = query.substr(i+1,pos-i+1);
				i = pos + 1;
			}
			token.push_back(temp);
		}
		else if (spos != std::string::npos)
		{
			temp = query.substr(i, spos - i);
			i = spos ;
			token.push_back(temp);
		}
		else
			break;
	}
	if (i < query.size())
		token.push_back(query.substr(i));
	cout << token.size() << endl;
	auto it = token.begin();
	while (it != token.end())
		cout << *it++ << endl;
}
//#endif
int main()
{
	string query;
	while (getline(cin, query))
		QueryParser(query);
	return 0;
}
