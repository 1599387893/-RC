#if 0
//µü´ú
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		ListNode* head = new ListNode(-1);
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
		temp->next = l1 == nullptr ? l2 : l1;
		return head->next;
	}
};


//µÝ¹é
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		if (l1->val <= l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};
#endif