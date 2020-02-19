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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res = new ListNode(0);
		ListNode* temp = res;
		int sum = 0;
		while (l1 || l2)
		{
			if (l1)  sum += l1->val;
			if (l2)  sum += l2->val;
			temp->next = new ListNode(sum % 10);
			temp = temp->next;
			if (l1)  l1 = l1->next;
			if (l2)  l2 = l2->next;
			sum /= 10;
		}
		if (sum)
			temp->next = new ListNode(1);
		return res->next;
	}
};
#endif

//ตÝน้
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry)
	{
		if (l1 == nullptr && l2 == nullptr && !carry)
			return nullptr;
		if (l1 == nullptr && l2 == nullptr && carry)
			return new ListNode(carry);
		int sum = carry;
		if (l1)
			sum += l1->val;
		if (l2)
			sum += l2->val;
		ListNode* temp = new ListNode(sum % 10);
		temp->next = addTwoNumbers(l1 == nullptr ? nullptr : l1->next, l2 == nullptr ? nullptr : l2->next, sum /= 10);
		return temp;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		return addTwoNumbers(l1, l2, 0);
	}
};
#endif