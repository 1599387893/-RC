#if 0
//����������
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr)
			return root;
		if (p->val > root->val && q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		if (p->val < root->val && q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		return root;
	}
};

//��ͨ������
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return NULL;
		//������ڵ����p����q�����ظ��ڵ�
		if (root == p || root == q)
			return root;
		//�ֱ�ȥ��������������
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		if (left && right)//p��q����һ�ߣ�˵����ǰ�ĸ����������ͬ���� 
			return root;
		else if (left)//˵��p��q����������
			return left;
		else if (right)//˵��p��q����������
			return right;
		else
			return NULL;

	}
};
#endif