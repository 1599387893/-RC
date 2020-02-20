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
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	vector<ListNode*> listOfDepth(TreeNode* tree) {
		vector<ListNode*> res;
		queue<TreeNode*> q;
		q.push(tree);
		TreeNode* node = nullptr;
		while (!q.empty())
		{
			ListNode* head = new ListNode(-1);
			ListNode* temp = head;
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				node = q.front();
				temp->next = new ListNode(node->val);
				q.pop();
				temp = temp->next;
				if (node->left != nullptr)  q.push(node->left);
				if (node->right != nullptr)q.push(node->right);
			}
			res.push_back(head->next);
		}
		return res;
	}
};
#endif