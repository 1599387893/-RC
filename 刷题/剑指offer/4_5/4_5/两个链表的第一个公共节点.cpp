//����ʹ������ָ�� node1��node2 �ֱ�ָ���������� headA��headB ��ͷ��㣬
//Ȼ��ͬʱ�ֱ��������;
//	�� node1 �������� headA ��ĩβʱ�����¶�λ������ headB ��ͷ��㣻
//	�� node2 �������� headB ��ĩβʱ�����¶�λ������ headA ��ͷ��㡣
//����������������ʱ����ָ��Ľ����ǵ�һ��������㡣

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr)
			return nullptr;
		ListNode* node1 = headA;
		ListNode* node2 = headB;
		while (node1 != node2)
		{
			node1 = (node1 == nullptr ? headB : node1->next);
			node2 = (node2 == nullptr ? headA : node2->next);
		}
		return node1;
	}
};



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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		map<ListNode*, int> m;
		while (headA)
		{
			m[headA]++;
			headA = headA->next;
		}
		while (headB)
		{
			m[headB]++;
			if (m[headB] == 2)
				break;
			headB = headB->next;
		}
		return headB;
	}
};