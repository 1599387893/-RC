/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
typedef struct ListNode Node;
struct ListNode* middleNode(struct ListNode* head) {
	if (NULL == head || NULL == head->next)
	{
		return head;
	}
	else
	{
		Node* pFast = head;
		Node* pSlow = head;
		while (pFast && pFast->next)
		{
			pFast = pFast->next->next;
			pSlow = pSlow->next;
		}
		return pSlow;
	}
}