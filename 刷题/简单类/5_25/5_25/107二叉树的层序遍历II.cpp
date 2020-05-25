/**
 * Definition for a binary tree node.
  * struct TreeNode {
   *     int val;
    *     TreeNode *left;
	 *     TreeNode *right;
	  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	   * };
	    */
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		//vector的头插
		vector<vector<int>> res;
		if (!root) return res;
		queue<TreeNode*> temp;
		temp.push(root);
		while (!temp.empty())
		{
			vector<int> arr;
			TreeNode* node  = nullptr;
			int size  = temp.size();
			for (int i  = 0; i < size; ++i)
			{
				node  = temp.front();
				temp.pop();
				if (node->left) temp.push(node->left);
				if (node->right) temp.push(node->right);
				arr.push_back(node->val);
			}
			res.insert(res.begin(), arr);
		}
		return res;
	}
};