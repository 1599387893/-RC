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
	int Depth(TreeNode* root)//ͳ�����������ڵ����
	{
		if (root == nullptr)
			return 0;
		int left = Depth(root->left);//�������ڵ����
		int right = Depth(root->right);//�������ڵ����
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