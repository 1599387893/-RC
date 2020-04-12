/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr)
			return head;
		unordered_map<Node*, Node*> um;
		//�Ƚ������˳��ԭ����Ϳ��������λ����unordered_map��������
		Node* temp = head;
		while (temp)
		{
			um[temp] = new Node(temp->val);
			temp = temp->next;
		}
		//�ڴ��������ÿһ���ڵ��next��randomָ��
		temp = head;
		while (temp)
		{
			if (temp->next)
				um[temp]->next = um[temp->next];
			if (temp->random)
				um[temp]->random = um[temp->random];
			temp = temp->next;
		}
		return um[head];
	}
};