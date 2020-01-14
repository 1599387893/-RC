#if 0
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	string defangIPaddr(string address) {
		string ret(address);
		string befor = ".";
		string after = "[.]";
		replace(ret.begin(), ret.end(),befor, after);
		return ret;
	}
};

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int myints[] = { 10, 20, 30, 30, 20, 10, 10, 20 };
	vector<int> myvector(myints, myints + 8);            // 10 20 30 30 20 10 10 20

	replace(myvector.begin(), myvector.end(), 20, 99); // 10 99 30 30 99 10 10 99

	cout << "myvector contains:";
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}
#endif

#include<iostream>
#include<string>
using namespace std;

string defangIPaddr1(string address) {
	string ret;
	auto pos = address.find('.');
	size_t befor = 0;
	for (int i = 0; i < 4; ++i)
	{
		ret += address.substr(befor, pos - befor);
		if (pos != string::npos)
			ret += "[.]";
		befor = pos + 1;
		pos = address.find( ".",befor);
	}
	
	return ret;
}
string defangIPaddr2(string address) {
	string ret(address);
	size_t befor = 0;
	for (int i = 0; i < 3; ++i)
	{
		auto pos = ret.find(".", befor);
		ret.replace(pos, 1, "[.]");
		befor = (pos + 3);
	}
	return ret;
}

string defangIPaddr3(string address) {
	string ret;
	for (auto e : address)
	{
		if (e == '.')
			ret += "[.]";
		else
			ret += e;
	}
	return ret;
}
int main()
{
	string str = "1.1.1.1";
	cout << defangIPaddr1(str) << endl;
	system("pause");
	return 0;
}