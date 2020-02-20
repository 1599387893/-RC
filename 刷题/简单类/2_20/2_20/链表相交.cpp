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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//消除高度差，将两条链分别合成为AB和BA形式，比较这俩个新链表是否相交
		ListNode* a = headA;
		ListNode* b = headB;
		while(a!=b)
		{
			a = a==nullptr ? headB : a->next;
			b = b==nullptr ? headA : b->next;
		}
		return a;
	}
};
#endif

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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* a = headA;
		ListNode* b = headB;
		ListNode* temp = b;
		while (a)
		{
			temp = b;
			while (temp && a != temp)
				temp = temp->next;
			if (temp)
				return temp;
			else
				a = a->next;
		}
		return nullptr;
	}
};
#endif

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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		map<ListNode*, int> mp;
		ListNode* temp = headA;
		while (temp)
		{
			mp[temp]++;
			temp = temp->next;
		}
		temp = headB;
		while (temp)
		{
			mp[temp]++;
			if (mp[temp] == 2)
				return temp;
			temp = temp->next;
		}
		return nullptr;
	}
};
#endif