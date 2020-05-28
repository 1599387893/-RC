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
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left && !root->right) return 1;
		int depth = INT_MAX;
		if (root->left) depth = min(depth, minDepth(root->left));
		if (root->right) depth = min(depth, minDepth(root->right));
		return depth + 1;
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
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left && !root->right) return 1;
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if (!root->left || !root->right)
			return 1 + left + right;
		return min(left, right) + 1;
	}
};