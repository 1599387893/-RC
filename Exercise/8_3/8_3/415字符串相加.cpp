#include <iostream>
#include <string>

using namespace std;

string addStrings1(string num1, string num2) {
	string res;
	int ad = 0, n = 0;
	int end1 = num1.size() - 1, end2 = num2.size() - 1;
	while (end1>=0 || end2>=0)
	{
		n = (end1 >= 0 ? num1[end1] - '0' : 0) + (end2 >= 0 ? num2[end2] - '0' : 0) + ad;
		ad = n / 10;
		n %= 10;
		res = to_string(n) + res;
		end1--;
		end2--;
	}
	if (ad)
		res = to_string(ad) + res;
	return res;
}
string addStrings(string num1, string num2) {
	string res;
	int n = 0;
	int end1 = num1.size() - 1, end2 = num2.size() - 1;
	while (end1 >= 0 || end2 >= 0 || n != 0)
	{
		n += (end1 >= 0 ? num1[end1] - '0' : 0) + (end2 >= 0 ? num2[end2] - '0' : 0);
		res = to_string(n%10) + res;
		n /= 10;
		end1--;
		end2--;
	}
	return res;
}
int main()
{
	string num1 = "1";
	string num2 = "99";
	cout << addStrings(num1, num2) << endl;
	return 0;
}