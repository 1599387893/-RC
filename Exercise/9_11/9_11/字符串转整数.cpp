#include <iostream>
#include <string>

using namespace std;
int strToInt(string& s)
{
	long long res = 0;
	bool symbol = false;
	int pos = 0;
	if (s[pos] == '-' || s[pos] == '+')
	{
		if (s[pos] == '-')
			symbol = true;
		pos++;
	}
	while (pos < s.size())
	{
		if (isdigit(s[pos]))
			res = res * 10 + s[pos++] - '0';
		else
			break;
	}
	if (pos != s.size())
		return 0;
	if (res > INT_MAX || res < INT_MIN)
		return 0;
	return symbol == true ? 0 - res : res;
}
int main()
{
	string  s = "123";
	cout << strToInt(s) << endl;
	return 0;
}