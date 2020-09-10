#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int n)
	{
		val = n;
	}
};
ListNode* reversePartLinkedlist(ListNode* head, int l, int r) {
	// write code here
	if (!head || !head->next) return head;
	stack<ListNode*> temp;
	ListNode* begin = head;
	ListNode* cur = head;
	ListNode* next = nullptr;
	for (int i = 1; i < l && cur; ++i)
	{
		begin = cur;
		cur = cur->next;
	}
	for (int i = l; i <= r && cur; ++i)
	{
		temp.push(cur);
		cur = cur->next;
		next = cur;
	}
	ListNode* newHead = begin == head ? nullptr : head;
	while (!temp.empty())
	{
		if (!newHead)
		{
			newHead = temp.top();
			temp.pop();
			begin = newHead;
			continue;
		}
		begin->next = temp.top();
		temp.pop();
		begin = begin->next;
	}
	begin->next = next;
	return newHead;
}
bool isReasonableOutSequece(vector<int>& ins, vector<int>& outs) {
	// write code here
	stack<int> sta;
	int pos_in = 0;
	int pos_out = 0;

	while (pos_in < ins.size() && pos_out < outs.size())
	{
		if (sta.empty() || (sta.top() != outs[pos_out]))
		{
			sta.push(ins[pos_in++]);
		}
		while (!sta.empty() && pos_out < outs.size() && sta.top() == outs[pos_out])
		{
			sta.pop();
			pos_out++;
		}
	}
	return sta.empty();
}
int main()
{
	ListNode* head = new ListNode(0);
	ListNode* temp = head;
	for (int i = 1; i < 6; ++i)
	{
		temp->next = new ListNode(i);
		temp = temp->next;
	}
	//reversePartLinkedlist(head->next, 1, 3);
	vector<int> in{1,2,3,4,5};
	vector<int> out{3,2,1,4,5};
	isReasonableOutSequece(in, out);
	return 0;
}