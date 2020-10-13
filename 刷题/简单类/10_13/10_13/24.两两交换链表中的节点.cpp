/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;
		vector<ListNode*> temp;
		ListNode* node = head;
		ListNode* cur = nullptr;
		while (node)
		{
			temp.push_back(node);
			cur = node;
			node = node->next;
			cur->next = nullptr;
		}
		for (int i = 0; i + 1 < temp.size(); i += 2)
			swap(temp[i], temp[i + 1]);
		node = temp[0];
		ListNode* ret = node;
		for (int i = 1; i < temp.size(); ++i)
		{
			node->next = temp[i];
			node = node->next;
		}
		return ret;
	}
};



/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* newHead = new ListNode(-1);
		newHead->next = head;
		ListNode* slow = newHead;
		ListNode* fast = newHead->next;
		ListNode* temp = nullptr;
		while (slow && fast && fast->next)
		{
			temp = fast->next->next;
			slow->next = fast->next;
			fast->next = temp;
			slow->next->next = fast;
			slow = fast;
			fast = slow->next;
		}
		return newHead->next;
	}
};