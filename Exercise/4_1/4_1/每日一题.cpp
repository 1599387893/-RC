//有效括号的嵌套深度
#include<iostream>
#include<string>
#include<vector>
using namespace std;


//嵌套深度为奇数的作为一个子序列，偶数的作为另一个子序列，
void maxDepthAfterSplit(string seq,vector<int>& ans) {
	int d = 0;
	ans.resize(seq.size());
	for (char& c : seq)
		ans[d++] = c == '(' ? d & 1 : ((d+1)&1);
}
int main()
{
	string str = "()(())()";
	vector<int> res;
	maxDepthAfterSplit(str, res);
}



vector<int> maxDepthAfterSplit(string seq) {
	int d = -1;
	vector<int> ans;
	for (char& c : seq)
		if (c == '(') {
		++d;
		ans.push_back(d % 2);
		}
		else {
			ans.push_back(d % 2);
			--d;
		}
		return ans;
}