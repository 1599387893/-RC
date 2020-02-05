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
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		if (preorder.size() == 0)
			return nullptr;
		TreeNode* root = new TreeNode(preorder[0]);//创建根节点
		for (int i = 1; i < preorder.size(); ++i)
		{
			TreeNode* node = new TreeNode(preorder[i]);
			//找到插入位置
			TreeNode* temp = root;
			while (temp)
			{
				if (temp->val > node->val)
				{
					if (temp->left == nullptr)
					{
						temp->left = node;
						break;
					}
					temp = temp->left;
				}
				else
				{
					if (temp->right == nullptr)
					{
						temp->right = node;
						break;
					}
					temp = temp->right;
				}
			}
		}
		return root;
	}
};
#endif