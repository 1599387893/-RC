/**
 * Definition for singly-linked list.
  * struct ListNode {
   *     int val;
    *     ListNode *next;
	 *     ListNode(int x) : val(x), next(NULL) {}
	  * };
	   */
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head  || !head->next) return head;
		ListNode* pre  = head;
		ListNode* temp  = head->next;
		while (temp)
		{
			if (temp->val  == pre->val)
				pre->next  = temp->next;
			else
				pre  = pre->next;
			temp  = temp->next;
		}
		return head;
	}
};