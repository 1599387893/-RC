//ตÝน้
#if 0
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val) {
val = _val;
}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/
class Solution {
public:
	vector<int> postorder(Node* root) {
		//ตÝน้
		vector<int> res;
		if (root == nullptr)
			return res;
		for (int i = root->children.size() - 1; i >= 0; --i)
		{
			vector<int> temp = postorder(root->children[i]);
			res.insert(res.begin(), temp.begin(), temp.end());
		}
		res.push_back(root->val);
		return res;
	}
};
#endif