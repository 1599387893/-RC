/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		ListNode* fast = A;
		ListNode* slow = A;
		ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
		ListNode* newtail = newhead;
		ListNode* front = newhead;
		newhead->next = A;

		//�ҵ�������Ŀ�ʼ�ĵط�
		while (fast && fast->next){
			front = front->next;
			fast = fast->next->next;
			slow = slow->next;
		}

		//�������Ϊ��������
		front->next = NULL;
		newhead->next = NULL;
		while (slow){
			if (newhead->next == NULL){
				newtail = slow;
				slow = slow->next;
				newhead->next = newtail;
				newtail->next = NULL;
			}
			else{
				newhead->next = slow;
				slow = slow->next;
				newhead->next->next = newtail;
				newtail = newhead->next;
			}
		}

		//�ж�����������Ĳ����Ƿ����
		newtail = newhead->next;
		slow = A;
		while (slow){
			if (newtail && (slow->val != newtail->val)){
				free(newhead);
				return 0;
			}
			newtail = newtail->next;
			slow = slow->next;
		}

		free(newhead);
		return 1;
	}
};