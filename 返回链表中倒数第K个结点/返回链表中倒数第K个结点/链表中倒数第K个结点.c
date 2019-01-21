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
	typedef struct ListNode Node;
	ListNode* removeElements(ListNode* head, int val)
	{
		Node* pCur = head;
		Node* pPer = NULL;
		while (pCur)
		{
			if (pCur->val == val)
			{
				if (pCur == head)
				{

					head = pCur->next;
					free(pCur);
					pCur = head;
				}
				else
				{
					pPer->next = pCur->next;
					free(pCur);
					pCur = pPer;
				}
			}
			else
			{
				pPer = pCur;
				pCur = pCur->next;
			}
		}
		return head;
	}
};