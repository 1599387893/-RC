#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> words{ { "Hello" }, { "Alaska" }, { "Dad" }, { "Peace" } };
	vector<string> key{ { "qwertyuiop" }, { "asdfghjkl" }, { "zxcvbnm" } };
	vector<string> res;
	for (int i = 0; i < words.size(); ++i)
	{
		if (key[0].find(words[i][0]) != string::npos)
		{
			bool flag = true;
			for (auto c : words[i])
				if (key[0].find(c) == string::npos)
					flag = false;
			if (flag == true)
				res.push_back(words[i]);
		}
		if (key[1].find(words[i][0]) != string::npos)
		{
			bool flag = true;
			for (auto c : words[i])
				if (key[1].find(c) == string::npos)
					flag = false;
			if (flag == true)
				res.push_back(words[i]);
		}
		if (key[2].find(words[i][0]) != string::npos)
		{
			bool flag = true;
			for (auto c : words[i])
				if (key[1].find(c) == string::npos)
					flag = false;
			if (flag == true)
				res.push_back(words[i]);
		}
	}
	return 0;
}