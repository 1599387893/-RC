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
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* res = head;
		ListNode* temp = head;
		while (k--)
			temp = temp->next;
		while (temp)
		{
			temp = temp->next;
			res = res->next;
		}
		return res;
	}
};