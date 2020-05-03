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
	TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		if (!target || !original || !cloned) return nullptr;
		if (target == original) return cloned;
		TreeNode* temp = getTargetCopy(original->left, cloned->left, target);
		return temp == nullptr ? getTargetCopy(original->right, cloned->right, target) : temp;
	}
};