
class Solution {
public:
	TreeNode* last = nullptr;
	void flatten(TreeNode* root) {
		if (!root) return;
		flatten(root->right);
		flatten(root->left);
		root->right = last;
		root->left = nullptr;
		last = root;
	}
};



//前序遍历
class Solution {
public:
	void PreOrder(TreeNode* root, vector<TreeNode*>& arr)
	{
		if (root)
		{
			arr.push_back(root);
			PreOrder(root->left, arr);
			PreOrder(root->right, arr);
		}
	}
	void flatten(TreeNode* root) {
		if (!root || (!root->left && !root->right)) return;
		vector<TreeNode*> arr;
		PreOrder(root, arr);
		for (int i = 0; i < arr.size() - 1; ++i)
		{
			arr[i]->right = arr[i + 1];
			arr[i]->left = nullptr;
		}
	}
};



//前序遍历+同步展开
class Solution {
public:
	void flatten(TreeNode* root) {
		if (!root || (!root->left && !root->right)) return;
		auto sta = stack<TreeNode*>();
		sta.push(root);
		TreeNode* prev = nullptr;
		while (!sta.empty())
		{
			TreeNode* curr = sta.top();
			sta.pop();
			if (prev)
			{
				prev->left = nullptr;
				prev->right = curr;
			}
			if (curr->right)
				sta.push(curr->right);
			if (curr->left)
				sta.push(curr->left);
			prev = curr;
		}
	}
};

//寻找前驱节点
class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode *curr = root;
		while (curr != nullptr) {
			if (curr->left != nullptr) {
				auto next = curr->left;
				auto predecessor = next;
				while (predecessor->right != nullptr) {
					predecessor = predecessor->right;
				}
				predecessor->right = curr->right;
				curr->left = nullptr;
				curr->right = next;
			}
			curr = curr->right;
		}
	}
};
