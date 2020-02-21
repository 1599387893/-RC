#if 0
class Solution {
public:
	//��Ϊ���������
	//1.ͬ�������� 2.ͬ�������� 3.�ֱ�������������
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