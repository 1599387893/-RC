#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int stringsplit(string& s)
{
	int count = 0, pos = 0;
	int n = 0;
	char c = s[0];
	while (pos < s.size())
	{
		while (n == 0 || pos < s.size() && c == s[pos])
			n++;
		while (n && pos < s.size() && c != s[pos])
		{
			n--;
			pos++;
		}
		count++;
	}
	return count;
}

typedef struct Node
{
	int val;
	struct Node* next;
	Node(int n = 0)
		:val(n)
		, next(nullptr)
	{}
}Node;

bool isLoop(Node* head)
{
	if (!head || !head->next) return false;
	Node* slow = head;
	Node* fast = head->next;
	while (fast && fast->next)
	{
		if (fast == slow)
			return true;
		slow = slow->next;
		fast = fast->next->next;
	}
	return false;
}
int main()
{
	//string s = "SKSSKKSSSSKKKK";
	//cout << stringsplit(s) << endl;
	Node* head = new Node();
	Node* temp = head;
	Node* pre = temp;
	for (int i = 1; i <= 4; ++i)
	{
		temp->next = new Node(i);
		pre = temp;
		temp = temp->next;
	}
	//pre->next = head->next->next;
	cout << isLoop(head) << endl;
	return 0;
}