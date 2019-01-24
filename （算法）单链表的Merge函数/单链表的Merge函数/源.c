/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	Node NewHead;
	Node* pNew = &NewHead;
	Node* ptr1 = l1;
	Node* ptr2 = l2;
	if (ptr1->val <= ptr2->val)
	{
		pNew = ptr1;
		ptr1 = ptr1->next;
	}
	else
	{
		pNew = ptr2;
		ptr2 = ptr2->next;
	}
	while (ptr1 && ptr2)
	{
		if (ptr1->val <= ptr2->val)
		{
			pNew->next = ptr1;
			ptr1 = ptr1->next;
		}
		else
		{
			pNew = ptr2;
			ptr2 = ptr2->next;
		}
		pNew = pNew->next;
	}
	if (ptr1)
		pNew = ptr1;
	else
		pNew = ptr2;

	return NewHead.next;
}