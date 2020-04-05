#if 0
#include<iostream>
#include<string>
using namespace std;

//从两边向中间比较
bool IsPalindrome1(const char* str, int n)
{
	if (str == nullptr || n < 1)
		return false;
	const char* left = str;
	const char* right = str + n - 1;
	while (left < right)
	{
		if (*left != *right)
			return false;
		++left;
		--right;
	}
	return true;
}
//从中间向两边找
bool IsPalindrome2(const char* str, int n)
{
	if (str == nullptr || n < 1)
		return false;
	int m = ((n >> 1) - 1) >= 0 ? (n >> 1) - 1 : 0;
	const char* left = str + m;
	const char* right = str + n - 1 - m;
	while (left >= str)
	{
		if (*left != *right)
			return false;
		--left;
		++right;
	}
	return true;

}
int main()
{
	string str = "abcdadcba";
	if (IsPalindrome2(str.c_str(),str.size()))
		cout << "Is Palindrome" << endl;
	else
		cout << "Is Not Palindrome" << endl;
	cin >> str;
	return 0;
}
#endif