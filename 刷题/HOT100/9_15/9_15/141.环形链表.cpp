/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (!head || !head->next) return false;
		ListNode* slow = head;
		ListNode* fast = head->next; //默认该链表是带头节点的，如果fast的初始值为head，可能我发进入循环
		while (fast && fast->next && fast != slow)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return fast == slow;
	}
};