#if 0
class Solution {
public:
	string restoreString(string s, vector<int>& indices) {
		string res(s);
		for (int i = 0; i < indices.size(); ++i)
			res[indices[i]] = s[i];
		return res;
	}
};

#endif


#include <iostream>
#include <string>
#include <vector>
using namespace std;
string restoreString(string s, vector<int>& indices) {
	int n = 0;
	int next = indices[0];
	int pre = 0;
	char temp;
	while (n < s.size())
	{
		temp = s[next];
		s[next] = s[pre];
		pre = next;
		next = indices[next];
		n++;
	}
	return s;
}
int main()
{
	string s = "codeleet";
	vector<int> arr{4,5,6,7,0,2,1,3};
	restoreString(s, arr);
}