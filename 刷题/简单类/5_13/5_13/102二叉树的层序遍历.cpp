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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* node = nullptr;
			vector<int> arr;
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				node = q.front();
				q.pop();
				arr.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			if (arr.size()>0)
				res.push_back(arr);
		}
		return res;
	}
};
#endif