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
	vector<int> _arr;
	void Exorder(TreeNode* root)
	{
		if (root)
		{
			Exorder(root->left);
			_arr.push_back(root->val);
			Exorder(root->right);
		}
	}
	bool isValidBST(TreeNode* root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr))
			return true;
		Exorder(root);
		for (int i = 0; i < _arr.size() - 1; ++i)
			if (_arr[i] >= _arr[i + 1])
				return false;
		return true;
	}
};
#endif
