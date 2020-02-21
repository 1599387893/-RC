#if 0
/*所谓 p 的后继节点，就是这串升序数字中，比 p 大的下一个。

如果 p 大于当前节点的值，说明后继节点一定在 RightTree
如果 p 等于当前节点的值，说明后继节点一定在 RightTree
如果 p 小于当前节点的值，说明后继节点一定在 LeftTree 或自己就是
递归调用 LeftTree，如果是空的，说明当前节点就是答案
如果不是空的，则说明在 LeftTree 已经找到合适的答案，直接返回即
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
