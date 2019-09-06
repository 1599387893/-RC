typedef struct ListNode Node;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	assert(head);
	if (head == NULL)
		return NULL;
	Node* Fast = head;
	Node* Slow = head;
	while (n-- && Fast)
	{
		Fast = Fast->next;
	}
	while (Fast->next)
	{
		Fast = Fast->next;
		Slow = Slow->next;
	}
	Slow->next = Slow->next->next;
	return head;
}
