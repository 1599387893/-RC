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
	bool isPalindrome(ListNode* head) {
		vector<int> temp1;
		ListNode* h = head;
		while (h)
		{
			temp1.push_back(h->val);
			h = h->next;
		}
		vector<int> temp2(temp1);
		reverse(temp2.begin(), temp2.end());
		for (int i = 0; i < temp1.size(); ++i)
			if (temp1[i] != temp2[i])
				return false;
		return true;
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
	bool isPalindrome(ListNode* head) {
		if (nullptr == head)
			return true;
		if (head->next == nullptr)
			return false;

		stack<int> sta;
		ListNode* temp = head;
		sta.push(temp->val);
		temp = temp->next;
		while (temp)
		{
			if (temp->val == sta.top())
				sta.pop();
			else
				sta.push(temp->val);
			temp = temp->next;
		}
		return sta.empty() ? true : false;
	}
};
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<errno.h>

int main()
{
	   key_t key;
	   key = 0x123456;
	   //  key = ftok("0x123456",'a');
	   //  printf("key = %d\n",key);
	   int msg_id, ret;
	   struct msgbuf{
	         int msgtype;
	         char mtext[10];
	
	
	   struct msgbuf msg_mbuf;
	 //  if(key != -1)
	 //  {
	 //      printf("�����ɹ�\n");
	 //  }
	 //  else
	 //  {
	 //      printf("����ʧ��\n");
	 //  }
	
	     msg_id = msgget(key, IPC_CREAT | 0x0666);
	
	     if (msg_id == -1)
	     {
	         printf("��Ϣ���н���ʧ��,������Ϊ:%s\n", strerror(errno));
	     }
	 else
	     {
	         printf("��Ϣ���н����ɹ�\n");
	     }
	
	     msg_mbuf.msgtype = 10;
	     memcpy(msg_mbuf.mtext, "������Ϣ", sizeof("������Ϣ"));
	     ret = msgsnd(msg_id, &msg_mbuf, sizeof("������Ϣ"), IPC_NOWAIT);
	
	     if (-1 == ret)
	     {
	         printf("������Ϣʧ��\n");
	     }
	    else
	     {
	         printf("������Ϣ�ɹ�\n");
	     }
	
	     ret = msgrcv(msg_id, &msg_mbuf, 10, 10, 0);
	
	     if (ret == -1)
	     {
	         printf("������Ϣʧ��\n");
	     }
	    else
	     {
	         printf("������Ϣ�ɹ�\n");
	     }
	
	     return 0;
 }