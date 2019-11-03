#include<iostream>
#include<string>
using namespace std;

int lengthOfLastWord(string s) {
	if (s.size() == 0 || (s.size() == 1 && *s.begin() == ' '))
		return 0;
	if (s.size() > 1 && s[s.size() - 1]== ' ')
		return 1;
	auto it = s.rfind(" ");
	if (it != -1)
		return s.size() - it - 1;
	return s.size();
}
int main()
{
	string s = " ";
	cout << lengthOfLastWord (s)<< endl;
	system("pause");
	return 0;
}