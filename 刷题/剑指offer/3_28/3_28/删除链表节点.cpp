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
	ListNode* deleteNode(ListNode* head, int val) {
		if (head == nullptr)
			return head;
		if (head->val == val)
			return head->next;
		ListNode* temp = head;
		while (temp->next)
		{
			if (temp->next->val == val)
			{
				temp->next = temp->next->next;
				break;
			}
			temp = temp->next;
		}
		return head;
	}
};