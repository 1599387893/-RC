#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
char* StrCpy(char* dest, const char* source)
{
	assert(dest);
	assert(source);
	char* ret = dest;
	while ((*dest++ = *source++)!='\0');
	return ret;
}
int main()
{
	char str[] = "abcd";
	char str2[] = "efg";
	printf("%s\n",StrCpy(str, str2));
	printf("%s\n", strcpy(str, str2));

	return 0;
}


#endif

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string ReverseKStep1(string& s,int k)
{
	string temp(s);
	temp += temp;
	size_t size = s.size();
	k %= size;
	return temp.substr(k, size);
}
string ReverseKStep2(string& s, const int k)
{
	string temp(s);
	reverse(temp.begin(), temp.begin() + k);
	reverse(temp.begin() + k, temp.end());
	reverse(temp.begin(), temp.end());
	return temp;
}
int main()
{
	string s = "abcdef";
	cout << ReverseKStep1(s, 2) << endl;
	cout << ReverseKStep2(s, 2) << endl;
	return 0;
}