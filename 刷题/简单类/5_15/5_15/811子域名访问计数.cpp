#if 0
class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		unordered_map<string, int> um;
		for (auto str : cpdomains)
		{
			int count = 0;
			string temp;
			for (int i = 0; str[i] != ' '; ++i)
				count = count * 10 + str[i] - '0';
			for (int i = str.size() - 1; i >= 0; --i)
			{
				while (i < str.size() && isalpha(str[i]))
					temp.insert(temp.begin(), str[i--]);
				if (str[i] == '.' || str[i] == ' ')
				{
					um[temp] += count;
					temp.insert(temp.begin(), '.');
				}
			}
		}
		vector<string> res;
		for (auto pair : um)
			res.push_back(to_string(pair.second) + ' ' + pair.first);
		return res;
	}
};


class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		unordered_map<string, int> um;
		for (auto str : cpdomains)
		{
			int pos = str.find(' ');
			int count = stoi(str.substr(0, pos));
			string domain = str.substr(pos + 1);
			while (pos > 0)
			{
				um[domain] += count;
				pos = domain.find('.');
				domain = domain.substr(pos + 1);
			}
		}
		vector<string> res;
		for (auto pair : um)
			res.push_back(to_string(pair.second) + ' ' + pair.first);
		return res;
	}
};
#endif