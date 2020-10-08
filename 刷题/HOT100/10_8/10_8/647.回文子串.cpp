#include <iostream>
#include <string>
#include <vector>
using namespace  std;
bool IsLoopStr(string s)
{
	string temp(s);
	reverse(temp.begin(), temp.end());
	return s == temp;
}
int countSubstrings(string s) {
	int count = s.size();
	for (int i = 0; i < s.size(); ++i)
		for (int j = i + 1; j < s.size(); ++j)
			if (IsLoopStr(s.substr(i, j - i)))
				count++;
	return count;
}

int main()
{
	countSubstrings("abc");

}