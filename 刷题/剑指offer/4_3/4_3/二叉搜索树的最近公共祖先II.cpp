#if 0
//1.在root的左子树和右子树同时找p和q，若p和q分别分布在root的左右子树，则root为所求
//2.若左子树返回NULL，则说明p和q都在右子树，则进入右子树做1.
//3.若右子树返回NULL，则说明p和q都在左子树，则进入左子树左1.


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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr)
			return nullptr;
		if (root == p || root == q)
			return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left && right)
			return root;
		return left ? left : right;
	}
};
#endif