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
	vector<int> preorder(Node* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		stack<Node*> sta;
		sta.push(root);
		while (!sta.empty())
		{
			Node* temp = sta.top();
			sta.pop();
			if (temp == nullptr)
				continue;
			res.push_back(temp->val);
			for (int i = temp->children.size() - 1; i >= 0; --i)
				sta.push(temp->children[i]);
		}
		return res;
	}
};
#endif

//µÝ¹é·½·¨
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
	vector<int> preorder(Node* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		res.push_back(root->val);
		if (!root->children.empty())
		{
			for (int i = 0; i < root->children.size(); ++i)
			{
				vector<int> temp = preorder(root->children[i]);
				res.insert(res.end(), temp.begin(), temp.end());
			}
		}
		return res;
	}
};
#endif
//·ÇµÝ¹é
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
		vector<int> res;
		if (root == nullptr)
			return res;
		stack<Node*> sta;
		sta.push(root);
		while (!sta.empty())
		{
			Node* temp = sta.top();
			sta.pop();
			res.insert(res.begin(), temp->val);
			if (!temp->children.empty())
			{
				for (int i = 0; i < temp->children.size(); ++i)
					sta.push(temp->children[i]);
			}
		}
		return res;
	}
};
#endif