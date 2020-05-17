/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class FindElements {
private:
	unordered_set<int> us;
public:
	FindElements(TreeNode* root) {
		//≤„–Ú±È¿˙
		queue<TreeNode*> q;
		root->val = 0;
		q.push(root);
		us.insert(0);
		while (!q.empty())
		{
			int size = q.size();
			TreeNode* node = nullptr;
			for (int i = 0; i < size; ++i)
			{
				node = q.front();
				q.pop();
				if (node->left)
				{
					node->left->val = node->val * 2 + 1;
					q.push(node->left);
					us.insert(node->left->val);
				}
				if (node->right)
				{
					node->right->val = node->val * 2 + 2;
					q.push(node->right);
					us.insert(node->right->val);
				}
			}
		}
	}

	bool find(int target) {
		return us.find(target) != us.end();
	}
};

/**
* Your FindElements object will be instantiated and called as such:
* FindElements* obj = new FindElements(root);
* bool param_1 = obj->find(target);
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
class FindElements {
private:
	unordered_set<int> us;
public:
	FindElements(TreeNode* root) {
		//≤„–Ú±È¿˙
		recover(root, 0);
	}
	void recover(TreeNode* root, int val)
	{
		if (!root) return;
		root->val = val;
		us.insert(val);
		recover(root->left, val * 2 + 1);
		recover(root->right, val * 2 + 2);
	}

	bool find(int target) {
		return us.find(target) != us.end();
	}
};

/**
* Your FindElements object will be instantiated and called as such:
* FindElements* obj = new FindElements(root);
* bool param_1 = obj->find(target);
*/