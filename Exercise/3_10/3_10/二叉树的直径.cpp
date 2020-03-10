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
	int res;
	int Depth(TreeNode* root)//统计左右子树节点个数
	{
		if (root == nullptr)
			return 0;
		int left = Depth(root->left);//左子树节点个数
		int right = Depth(root->right);//右子树节点个数
		res = max(res, left + right + 1);
		return max(left, right) + 1;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		res = 1;
		Depth(root);
		return res - 1;
	}
};
#endif