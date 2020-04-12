//使用vector
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
		//使用一个数组顺序保存所有节点；
		//重新改变各节点之间的指向；
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


//递归

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
			helper(root->left, head, pre);//先处理左子树与根节点的关系；
			if (!head)//此时找到最小元素
			{
				head = root;
				pre = root;
			}
			else
			{
				//pre代表的是root的前一个节点
				pre->right = root;
				root->left = pre;
				pre = root;
			}
			helper(root->right, head, pre); //再处理右子树与根节点的关系；
		}
	}
};