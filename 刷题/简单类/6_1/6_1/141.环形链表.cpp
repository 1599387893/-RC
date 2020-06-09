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
		ListNode* fast = head->next;
		ListNode* slow = head;
		while (fast && fast->next && fast != slow)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		return fast == slow ? true : false;
	}
};
