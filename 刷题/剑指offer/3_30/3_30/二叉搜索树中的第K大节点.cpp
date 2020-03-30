//优先级队列（默认大根堆）
class Solution {
public:
	priority_queue<int> pq;
	void inorder(TreeNode* root)
	{
		if (root)
		{
			inorder(root->left);
			pq.push(root->val);
			inorder(root->right);
		}
	}
	int kthLargest(TreeNode* root, int k) {
		inorder(root);
		while (--k)
			pq.pop();
		return pq.top();
	}
};







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

    multiset<int,greater<int>> ms;
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            ms.insert(root->val);
            inorder(root->right);
        }
    }
    int kthLargest(TreeNode* root, int k) {
        inorder(root);
        auto it = ms.begin();
        while(--k)
            it++;
        return (*it);
    }
};