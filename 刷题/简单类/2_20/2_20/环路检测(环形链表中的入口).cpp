//快慢指针法
//1.设置快慢指针2.找到第一次相遇3.再出发慢指针4.相遇即所求
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
	ListNode *detectCycle(ListNode *head) {
		if(head==nullptr || head->next == nullptr)
			return nullptr;
		ListNode* fast = head;
		ListNode* slow = head;
		while(fast&&fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if(fast == slow)
				break;
		}
		if(!fast || !fast->next)
			return nullptr;
		slow = head;
		while(slow!=fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;

	}
};
#endif


//使用容器保存遍历过的节点，当在遇到相同的即为入口
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
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return nullptr;
		map<ListNode*, int> mp;
		ListNode* temp = head;
		while (temp)
		{
			mp[temp]++;
			if (mp[temp] == 2)
				break;
			temp = temp->next;
		}
		return temp;
	}
};
#endif