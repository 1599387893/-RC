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
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* pre = nullptr;
		ListNode* cur = head;
		ListNode* next = cur->next;
		while (next)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};


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
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* node = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return node;
	}
};