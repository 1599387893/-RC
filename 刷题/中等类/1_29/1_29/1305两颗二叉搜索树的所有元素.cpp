//-----------±È¿˙+≈≈–Ú------
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
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> res;
		getAllElements(root1, res);
		getAllElements(root2, res);
		sort(res.begin(), res.end());
		return res;
	}
	void getAllElements(TreeNode* root1, vector<int>& res)
	{
		if (root1)
		{
			res.push_back(root1->val);
			getAllElements(root1->left, res);
			getAllElements(root1->right, res);
		}
	}
};
#endif

//----------------÷––Ú±È¿˙+πÈ≤¢≈≈–Ú---------------
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
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> res;
		vector<int> res1, res2;
		getAllElements(root1, res1);
		getAllElements(root2, res2);
		//sort(res.begin(),res.end());
		//πÈ≤¢≈≈–Ú
		int i = 0, j = 0;
		while (i < res1.size() && j < res2.size())
		{
			while (i<res1.size() && j<res2.size() && res1[i] <= res2[j])
				res.push_back(res1[i++]);
			while (j<res2.size() && i<res1.size() && res1[i] >= res2[j])
				res.push_back(res2[j++]);
		}
		if (i == res1.size())
			res.insert(res.end(), res2.begin() + j, res2.end());
		if (j == res2.size())
			res.insert(res.end(), res1.begin() + i, res1.end());

		return res;
	}
	void getAllElements(TreeNode* root1, vector<int>& res)
	{
		if (root1)
		{
			getAllElements(root1->left, res);
			res.push_back(root1->val);
			getAllElements(root1->right, res);
		}
	}
};
#endif


#if 0
class Solution {
public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> res;
		vector<int> res1, res2;
		getAllElements(root1, res1);
		getAllElements(root2, res2);
		//sort(res.begin(),res.end());
		//πÈ≤¢≈≈–Ú
		int i = 0, j = 0;
		while (i < res1.size() || j < res2.size()) {
			if (i < res1.size() && (j == res2.size() || res1[i] <= res2[j])) {
				res.push_back(res1[i++]);
			}
			else {
				res.push_back(res2[j++]);
			}
		}
		return res;
	}
	void getAllElements(TreeNode* root1, vector<int>& res)
	{
		if (root1)
		{
			getAllElements(root1->left, res);
			res.push_back(root1->val);
			getAllElements(root1->right, res);
		}
	}
#endif