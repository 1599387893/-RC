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
		if (root == nullptr)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		bool order = false; //用来判断打印的方向
		while (!q.empty())
		{
			vector<int> temp;
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				TreeNode* node = q.front();
				q.pop();
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
				temp.push_back(node->val);
			}
			if (order)
				reverse(temp.begin(), temp.end());
			order = !order;
			res.push_back(temp);
		}
		return res;
	}
};
#endif