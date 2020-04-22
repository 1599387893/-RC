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
	//层序遍历，只保留每一层的最后一个数
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			res.push_back(q.back()->val);
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				TreeNode* temp = q.front();
				q.pop();
				if (temp->left)
					q.push(temp->left);
				if (temp->right)
					q.push(temp->right);
			}
		}
		return res;
	}
};