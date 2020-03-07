#if 0

// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string name_list;
	string target_name;
	while (getline(cin, name_list))
	{
		getline(cin, target_name);
		if (target_name.size() == 0 || target_name[0]==' '|| name_list.size() == 0)
		{
			cout << "Ignore" << endl;
			continue;
		}
		auto pos = name_list.find(target_name);
		if (pos == string::npos)
			cout << "Important!" << endl;
		else
		{
			if (pos != 0 && name_list[pos - 1] != '"')
				cout << "Important!" << endl;
			else
				cout << "Ignore" << endl;
		}
	}
	return 0;
}

#endif