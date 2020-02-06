//(中序遍历非递归)T:O(1) S : O(h)
//初始化的时候先把root的所有左边的节点入栈
//hasNext只要栈不空就是还有下一个元素
//next，取出栈顶元素p(当前返回值)。把p的右子树的左节点全部入栈。

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
class BSTIterator {
public:
	stack<TreeNode*> sta;
	BSTIterator(TreeNode* root) {
		TreeNode* temp = root;
		while (temp)
		{
			sta.push(temp);
			temp = temp->left;
		}
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* temp = sta.top();
		sta.pop();
		int ret = temp->val;
		temp = temp->right;
		while (temp)
		{
			sta.push(temp);
			temp = temp->left;
		}
		return ret;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !sta.empty();
	}
};

/**
* Your BSTIterator object will be instantiated and called as such:
* BSTIterator* obj = new BSTIterator(root);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/
#endif
