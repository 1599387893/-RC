#if 0
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode* res = new ListNode(-1);
		ListNode* temp = res;
		while (l1 && l2)
		{
			if (l1->val > l2->val)
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
		if (l1)
			temp->next = l1;
		if (l2)
			temp->next = l2;
		return res->next;
	}
};

//ตÝน้

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		if (l1->val > l2->val)
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
};
#endif