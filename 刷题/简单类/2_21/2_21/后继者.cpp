#if 0
/*��ν p �ĺ�̽ڵ㣬�����⴮���������У��� p �����һ����

��� p ���ڵ�ǰ�ڵ��ֵ��˵����̽ڵ�һ���� RightTree
��� p ���ڵ�ǰ�ڵ��ֵ��˵����̽ڵ�һ���� RightTree
��� p С�ڵ�ǰ�ڵ��ֵ��˵����̽ڵ�һ���� LeftTree ���Լ�����
�ݹ���� LeftTree������ǿյģ�˵����ǰ�ڵ���Ǵ�
������ǿյģ���˵���� LeftTree �Ѿ��ҵ����ʵĴ𰸣�ֱ�ӷ��ؼ�
*/
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
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (root == nullptr || p == nullptr)
			return nullptr;
		if (root->val <= p->val)
			return inorderSuccessor(root->right, p);
		else
		{
			TreeNode* node = inorderSuccessor(root->left, p);
			if (node == nullptr)
				return root;
			else
				return node;
		}
	}
};
#endif
