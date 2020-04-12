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
		//先将链表的顺序将原链表和拷贝链表的位置用unordered_map关联起来
		Node* temp = head;
		while (temp)
		{
			um[temp] = new Node(temp->val);
			temp = temp->next;
		}
		//在处理链表的每一个节点的next和random指针
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