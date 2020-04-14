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
		if (!l1 || l1->val == 0)   return l2;
		if (!l2 || l2->val == 0)   return l1;
		stack<int> s1, s2;
		int carry = 0; //标记进位
		int temp = 0; //每相同位的求和结果
		ListNode* node1 = l1, *node2 = l2;
		while (node1)
		{
			s1.push(node1->val);
			node1 = node1->next;
		}
		while (node2)
		{
			s2.push(node2->val);
			node2 = node2->next;
		}
		while (!s1.empty() || !s2.empty() || carry)
		{
			temp = carry;
			if (!s1.empty())
			{
				temp += s1.top();
				s1.pop();
			}
			if (!s2.empty())
			{
				temp += s2.top();
				s2.pop();
			}
			carry = temp / 10;
			temp %= 10;
			node1 = new ListNode(temp);
			node1->next = node2;
			node2 = node1;
		}
		return node1;
	}
};