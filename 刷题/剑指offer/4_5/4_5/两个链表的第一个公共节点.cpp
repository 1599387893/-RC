//我们使用两个指针 node1，node2 分别指向两个链表 headA，headB 的头结点，
//然后同时分别逐结点遍历;
//	当 node1 到达链表 headA 的末尾时，重新定位到链表 headB 的头结点；
//	当 node2 到达链表 headB 的末尾时，重新定位到链表 headA 的头结点。
//这样，当它们相遇时，所指向的结点就是第一个公共结点。

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