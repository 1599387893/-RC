#include<iostream>
#include<string>
#include<vector>
using namespace std;

int romanToInt(string s) {
	int num = 0;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		if (s[i] == 'I')
		{
			if (i<s.size() - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X'))
				num -= 1;
			else
				num += 1;
		}
		else if (s[i] == 'V')
		{
			num += 5;
		}
		else if (s[i] == 'X')
		{
			if (i<s.size() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C'))
				num -= 10;
			else
				num += 10;
		}
		else if (s[i] == 'L')
		{
			num += 50;
		}
		else if (s[i] == 'C')
		{
			if (i<s.size() - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M'))
				num -= 100;
			else
				num += 100;
		}
		else if (s[i] == 'D')
		{
			num += 500;
		}
		else if (s[i] == 'M')
		{
			num += 1000;
		}
	}
	return num;
}

string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0)
		return "";
	
	string ret;
	int min = strs[0].size();
	for (int i = 0; i<strs.size(); ++i)
		if (strs[i].size() < min)
			min = strs[i].size();
	for (int i = 0; i <= min; ++i)
	{
		char temp = strs[0][i];
		bool flag = true;
		int j;
		for (j = 1; j<strs.size(); ++j)
		{
			if (strs[j][i] != temp)
			{
				flag = false;
				break;
			}
		}
		if (flag == false)
			break;
		ret += temp;
	}
	return ret;
}
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;

	ListNode* head = nullptr;
	if (l1->val >= l2->val)
	{
		head = l2;
		l2 = l2->next;
	}
	else
	{
		head = l1;
		l1 = l1->next;
	}
	ListNode* temp = head;
	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->val >= l2->val)
		{
			temp->next = l2;
			l2 = l2->next;
		}
		else
		{
			temp->next = l1;
			l1 = l1->next;
		}
		temp = temp->next;
	}
	if (l1 != nullptr)
		temp->next = l1;
	if (l2 != nullptr)
		temp->next = l2;
	return head;
}

int main()
{
	vector<string> strs;
	strs.resize(3);
	strs[0] = "flower";
	strs[1] = "flow";
	strs[2] = "flight";
	//string s;
	//char s1;
	//while (cin >> s>>s1)
	//{
	//	//cout << romanToInt(s) << endl;
	//	cout << (s += s1) << endl;
	//}
	cout << longestCommonPrefix(strs) << endl;
	system("pause");
	return 0;
}