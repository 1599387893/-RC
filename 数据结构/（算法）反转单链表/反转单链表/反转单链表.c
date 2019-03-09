/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
typedef struct ListNode Node;
struct ListNode* reverseList(struct ListNode* head) {
	Node *root = head;
	Node *pre = NULL;
	Node *next = NULL;

	if (head == NULL)
		return NULL;

	while (root->next){
		next = root->next;
		root->next = pre;
		pre = root;
		root = next;
	}
	root->next = pre;
	return root;
}