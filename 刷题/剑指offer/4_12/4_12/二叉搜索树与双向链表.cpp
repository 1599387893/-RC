//ʹ��vector
class Solution {
public:
	void InOrder(vector<Node*>& temp, Node* root)
	{
		if (root)
		{
			if (root->left)
				InOrder(temp, root->left);
			temp.push_back(root);
			if (root->right)
				InOrder(temp, root->right);
		}
	}
	Node* treeToDoublyList(Node* root) {
		//ʹ��һ������˳�򱣴����нڵ㣻
		//���¸ı���ڵ�֮���ָ��
		if (!root)
			return root;
		vector<Node*> temp;
		InOrder(temp, root);
		for (int i = 0; i < temp.size() - 1; ++i)
		{
			temp[i]->right = temp[i + 1];
			temp[i + 1]->left = temp[i];
		}
		temp[0]->left = temp[temp.size() - 1];
		temp[temp.size() - 1]->right = temp[0];
		return temp[0];

	}
};


//�ݹ�

class Solution {
public:
	Node* treeToDoublyList(Node* root) {
		if (!root)
			return root;
		Node* head = nullptr, *pre = nullptr;
		helper(root, head, pre);
		head->left = pre;
		pre->right = head;
		return head;
	}
	void helper(Node* root, Node*& head, Node*& pre)
	{
		if (root)
		{
			helper(root->left, head, pre);//�ȴ�������������ڵ�Ĺ�ϵ��
			if (!head)//��ʱ�ҵ���СԪ��
			{
				head = root;
				pre = root;
			}
			else
			{
				//pre�������root��ǰһ���ڵ�
				pre->right = root;
				root->left = pre;
				pre = root;
			}
			helper(root->right, head, pre); //�ٴ�������������ڵ�Ĺ�ϵ��
		}
	}
};