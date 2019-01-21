/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	typedef struct ListNode Node;
	ListNode* partition(ListNode* pHead, int x) {
		if (pHead == NULL || NULL == pHead->next)
		{
			return pHead;
		}
		else
		{
			Node GreaterList(0);
			Node LessList(0);
			Node* greaterList = &GreaterList;
			Node* lessList = &LessList;

			while (pHead)
			{
				if (pHead->val < x)
				{
					lessList->next = pHead;
					lessList = lessList->next;
					pHead = pHead->next;
				}
				else
				{
					greaterList->next = pHead;
					greaterList = greaterList->next;
					pHead = pHead->next;
				}
			}
			lessList->next = GreaterList.next;
			greaterList->next = NULL;
			return LessList.next;
		}
	}
};