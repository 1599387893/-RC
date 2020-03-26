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
	int Depth(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		if (root->left == nullptr && root->right == nullptr)
			return 1;
		int left = Depth(root->left);
		int right = Depth(root->right);
		return left>right ? left + 1 : right + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
			return true;
		if (root->left == nullptr && root->right == nullptr)
			return true;
		int left = 0, right = 0;
		if (root->left)
			left = Depth(root->left);
		if (root->right)
			right = Depth(root->right);
		if (abs(left - right) > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}
};