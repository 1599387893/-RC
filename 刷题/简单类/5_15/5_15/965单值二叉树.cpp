#if 0
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
	bool isUnivalTree(TreeNode* root, const int n)
	{
		if (!root) return true;
		if (root->val != n) return false;
		return isUnivalTree(root->left, n) && isUnivalTree(root->right, n);
	}
	bool isUnivalTree(TreeNode* root) {
		if (!root) return true;
		if (!root->left && !root->right) return true;
		return isUnivalTree(root, root->val);
	}
};
#endif