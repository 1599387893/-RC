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
		ListNode* slow = head;
		ListNode* fast = head->next; //Ĭ�ϸ������Ǵ�ͷ�ڵ�ģ����fast�ĳ�ʼֵΪhead�������ҷ�����ѭ��
		while (fast && fast->next && fast != slow)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return fast == slow;
	}
};