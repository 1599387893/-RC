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
	bool IsSameTree(TreeNode* t1, TreeNode* t2)
	{
		if (!t1&&!t2) return true;
		if ((!t1&&t2) || (t1&&!t2)) return false;
		return IsSameTree(t1->left, t2->left) && IsSameTree(t1->right, t2->right);
	}
	bool checkSubTree(TreeNode* t1, TreeNode* t2) {
		if (!t2) return true;
		if (!t1) return false;
		if ((t1->val == t2->val) && (IsSameTree(t1, t2)))
			return true;
		return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
	}
};

//中序遍历特点
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
	void Inorder(TreeNode* t, string& s)
	{
		if (t)
		{
			Inorder(t->left, s);
			s.push_back(t->val);
			Inorder(t->right, s);
		}
	}
	bool checkSubTree(TreeNode* t1, TreeNode* t2) {
		if (!t2) return true;
		if (!t1&&t2) return false;
		string s1 = "", s2 = "";
		Inorder(t1, s1);
		Inorder(t2, s2);
		if (s1.find(s2) == string::npos) return false;
		return true;
	}
};
#endif