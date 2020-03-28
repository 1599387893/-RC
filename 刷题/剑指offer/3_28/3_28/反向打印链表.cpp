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
	vector<int> res;
	vector<int> reversePrint(ListNode* head) {
		if (head == nullptr)
			return res;
		reversePrint(head->next);
		res.push_back(head->val);
		return res;
	}
};





class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		stack<int> temp;
		vector<int> res;
		while (head)
		{
			temp.push(head->val);
			head = head->next;
		}
		while (!temp.empty())
		{
			res.push_back(temp.top());
			temp.pop();
		}
		return res;
	}
};