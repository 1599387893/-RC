/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	void PostOrder(TreeNode* root, const int& target, TreeNode* pre)
	{
		if (!root) return;
		PostOrder(root->left, target, root);
		PostOrder(root->right, target, root);
		if (root->val == target && !root->left && !root->right && pre)
			pre->left == root ? pre->left = nullptr : pre->right = nullptr;
	}
	TreeNode* removeLeafNodes(TreeNode* root, int target) {
		if (!root) return nullptr;
		PostOrder(root, target, nullptr);
		if (root->val == target && !root->left && !root->right) return nullptr;
		return root;
	}
};

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* removeLeafNodes(TreeNode* root, int target) {
		if (!root) return nullptr;
		root->left = removeLeafNodes(root->left, target);
		root->right = removeLeafNodes(root->right, target);
		if (root->val == target && !root->left && !root->right) return nullptr;
		return root;
	}
};