#if 0
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	bool isSymmetric(TreeNode* node1, TreeNode* node2)
	{
		if (!node1 && !node2) return true;
		if ((!node1 && node2) || (node1 && !node2) || (node1->val != node2->val)) return false;
		return isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
	}
	bool isSymmetric(TreeNode* root) {
		if (!root || (!root->left && !root->right)) return true;
		return isSymmetric(root->left, root->right);
	}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root || (!root->left && !root->right)) return true;
		TreeNode* node1 = nullptr;
		TreeNode* node2 = nullptr;
		queue<TreeNode*> que;
		que.push(root);
		que.push(root);
		while (!que.empty())
		{
			node1 = que.front(); que.pop();
			if (que.empty())
				return false;
			node2 = que.front(); que.pop();
			if (!node1 && !node2)
				continue;
			if ((!node1 && node2) || (node1 && !node2) || (node1->val != node2->val))
				return false;
			que.push(node1->left);
			que.push(node2->right);
			que.push(node1->right);
			que.push(node2->left);
		}
		return true;
	}
};
#endif