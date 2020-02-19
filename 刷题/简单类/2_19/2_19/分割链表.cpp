#if 0
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
	ListNode* partition(ListNode* head, int x) {
		if(head == nullptr || head->next == nullptr)
			return head;
		ListNode* less = head;
		ListNode* great = head;
		while(less && great)
		{
			//首先要找到大于基准值的节点，再从该节点向后找小于基准值的节点
			while(less && less->val < x)
				less = less->next;
			great = less;
			while(great && great->val >= x)
				great = great->next;
			if(less && great && less!=great)
				swap(great->val,less->val); 
		}
		return head;
	}
};
#endif