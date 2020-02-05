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
	TreeNode* pruneTree(TreeNode* root) {
		if (root == nullptr)
			return nullptr;
		//深度优先；
		root->left = pruneTree(root->left);
		root->right = pruneTree(root->right);
		if (root->val == 0 && root->left == nullptr && root->right == nullptr)
			return nullptr;
		return root;
	}
};
#endif