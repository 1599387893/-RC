//(��������ǵݹ�)T:O(1) S : O(h)
//��ʼ����ʱ���Ȱ�root��������ߵĽڵ���ջ
//hasNextֻҪջ���վ��ǻ�����һ��Ԫ��
//next��ȡ��ջ��Ԫ��p(��ǰ����ֵ)����p������������ڵ�ȫ����ջ��

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
