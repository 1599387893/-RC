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
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		if (root->left == nullptr && root->right == nullptr)
			return 1;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return left > right ? left + 1 : right + 1;
	}
};