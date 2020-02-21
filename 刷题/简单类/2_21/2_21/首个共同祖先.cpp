#if 0
class Solution {
public:
	//分为三种情况：
	//1.同在左子树 2.同在右子树 3.分别在左右子树；
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || p == root || q == root)
			return nullptr;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		if (left && right)
			return root;
		return left ? left : right;
	}
};
#endif