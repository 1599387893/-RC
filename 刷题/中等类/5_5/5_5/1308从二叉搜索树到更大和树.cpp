//��ͨ������û���õ�����������������
class Solution {
public:
	vector<int> nodeValue;
	void GetValue(TreeNode* root)
	{
		if (!root) return;
		nodeValue.push_back(root->val);
		GetValue(root->left);
		GetValue(root->right);
	}
	void UpdateNode(TreeNode* root)
	{
		if (!root) return;
		int Old = root->val;
		int New = 0;
		for (auto n : nodeValue)
			if (n >= Old)
				New += n;
		root->val = New;
		UpdateNode(root->left);
		UpdateNode(root->right);
	}
	TreeNode* bstToGst(TreeNode* root) {
		if (!root || (!root->left && !root->right)) return root;
		GetValue(root);
		sort(nodeValue.begin(), nodeValue.end());
		UpdateNode(root);
		return root;
	}
};

//��Ч������

class Solution {
public:
	int sum;
	void UpdateNode(TreeNode* root)
	{
		if (!root) return;
		if (root->right)
			UpdateNode(root->right);
		sum += root->val;
		root->val = sum;
		if (root->left)
			UpdateNode(root->left);
	}
	TreeNode* bstToGst(TreeNode* root) {
		//�Ӹ��������Ԫ�ؿ�ʼ���£�������½����
		//������ʽ������->��->���˳��
		sum = 0;
		UpdateNode(root);
		return root;
	}
};