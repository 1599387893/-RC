//µÝ¹é
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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if(root==nullptr)
			return res;
		rightSideView(root,res,0);
		return res;
	}
	void rightSideView(TreeNode* root,vector<int>& res,int level)
	{
		if(root==nullptr)
			return ;
		if(res.size() == level)
			res.push_back(root->val);
		rightSideView(root->right,res,level+1);
		rightSideView(root->left,res,level+1);
	}
};
#endif

//·ÇµÝ¹é
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
#endif