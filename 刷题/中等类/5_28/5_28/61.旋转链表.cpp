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
	int Length(ListNode* head)
	{
		if (!head) return 0;
		if (!head->next) return 1;
		return 1 + Length(head->next);
	}
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next) return head;
		int length = Length(head);
		k %= length;
		if (!k) return head;
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* pre1 = nullptr;
		ListNode* pre2 = nullptr;
		while (fast && k--)
			fast = fast->next;
		while (fast)
		{
			pre1 = fast;
			pre2 = slow;
			fast = fast->next;
			slow = slow->next;
		}
		pre1->next = head;
		pre2->next = nullptr;
		return slow;
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
	int Length(ListNode* head)
	{
		if (!head) return 0;
		if (!head->next) return 1;
		return 1 + Length(head->next);
	}
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next) return head;
		int length = Length(head);
		k %= length;
		if (!k) return head;
		ListNode* fast = head;
		ListNode* slow = head;
		while (k--)
			fast = fast->next;
		while (fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}
		fast->next = head;
		ListNode* res = slow->next;
		slow->next = nullptr;
		return res;
	}
};