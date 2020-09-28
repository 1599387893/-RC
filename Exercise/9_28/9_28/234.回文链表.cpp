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
	void GetAllVal(ListNode* head, vector<int>& ListVal)
	{
		if (!head) return;
		ListVal.push_back(head->val);
		GetAllVal(head->next, ListVal);
	}
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) return true;
		vector<int> ListVal;
		GetAllVal(head, ListVal);
		int begin = 0, end = ListVal.size() - 1;
		while (begin < end)
		{
			if (ListVal[begin] != ListVal[end])
				return false;
			begin++;
			end--;
		}
		return true;
	}
};