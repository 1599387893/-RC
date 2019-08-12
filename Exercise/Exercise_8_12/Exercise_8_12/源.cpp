
#include<iostream>
#include<string>
using namespace std;

typedef char STRING[255] ;

int main()
{
#if 0
	int i = 0;
	int j = 0;
	if ((++j) || (++i) > 0)
		cout << i << " " << j << endl;
	STRING s;
	cout << typeid(s).name() << endl;
#endif

	char *p1[5];
	char(*p2)[5];
	char *(p3[5]);
	cout << typeid(p1).name() << endl;
	cout << typeid(p2).name() << endl;
	cout << typeid(p3).name() << endl;

	system("pause");
	return 0;
}


/**
* Definition for singly-linked list.
*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* newHead = nullptr;
		while (head)
		{
			ListNode* ptr = new ListNode(head->val);
			ptr->next = newHead;
			newHead = ptr;
			head = head->next;
		}
		return newHead;
	}
};
class Solution {
public:
	ListNode* reverseList(ListNode* head)
	{
		ListNode* temp;
		if (head == nullptr || head->next == nullptr)
			return head;
		else
		{
			temp = reverseList(head->next);
			ListNode* ptr = temp;
			while (ptr && ptr->next)
				ptr = ptr->next;
			head->next = nullptr;
			ptr->next = head;
		}
		return temp;
	}
};