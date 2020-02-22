#pragma once

#include<iostream>
#include<vector>
using namespace std;
template<class T>
struct BSTreeNode
{
	T val;
	struct BSTreeNode<T>* left;
	struct BSTreeNode<T>* right;
	BSTreeNode(const T& _val)
		:val(_val)
		, left(nullptr)
		, right(nullptr)
	{}
};

template<class T>
class BSTree
{
	typedef struct BSTreeNode<T> Node;
	typedef Node* PNode;
private:
	PNode root;
public:
	BSTree() :root(nullptr)
	{}
	//插入bool Insert(const T& data)
	bool Insert(const T& data)
	{
		if (root == nullptr)
		{
			root = new Node(data);
			return true;
		}
		//找到插入位置
		PNode temp = root;
		while (1)
		{
			if (temp->val == data)
				return false;
			if (temp->val > data)
			{
				if (temp->left == nullptr)
				{
					temp->left = new Node(data);
					return true;
				}
				else
					temp = temp->left;
			}
			if (temp->val < data)
			{
				if (temp->right == nullptr)
				{
					temp->right = new Node(data);
					return true;
				}
				else
					temp = temp->right;
			}
		}
	}
	//删除bool Erase(const T& data)
	bool Erase(const T& data)
	{
		if (root == nullptr)
			return true;
		PNode pCur = root;
		PNode parent = nullptr;
		while (pCur)
		{
			if (pCur->val == data)
				break;
			parent = pCur;
			if (pCur->val > data)
				pCur = pCur->left;
			else
				pCur = pCur->right;
		}
		if (pCur == nullptr)
			return false;
		
		//1.只有左子树--->直接删除
		//2.只有右子树--->直接删除
		//3.左右子树都不存在--->直接删除
		//4.左右子树都存在
		if (!pCur->right)
		{
			if (root == pCur)
				root = pCur->left;
			if (parent->left == pCur)
				parent->left = pCur->left;
			else
				parent->right = pCur->left;
			delete pCur;
		}
		else if (!pCur->left)
		{
			if (pCur == root)
				root = pCur->right;
			if (parent->left == pCur)
				parent->left = pCur->right;
			else
				parent->right = pCur->right;
			delete pCur;
		}
		else
		{
			//找出pCur左子树中最大的，或者pCur右子树中最小的，将pCur替换；
			PNode temp = pCur->left;
			parent = pCur;
			while (temp->right)
			{
				parent = temp;
				temp = temp->right;
			}
			pCur->val = temp->val;
			if (parent == pCur)
				pCur->left = nullptr;
			else
				parent->right = nullptr;
			delete temp;
		}
		return true;

#if 0

		//空树
		if (root == nullptr)
			return false;
		//非空
		PNode pCur = root;
		PNode pParent = nullptr;

		//1.查找data在树中的位置
		while (pCur)
		{
			if (data == pCur->val)
				break;
			else if (data > pCur->val)
			{
				pParent = pCur;
				pCur = pCur->right;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->left;
			}
		}
		//data不在二叉树中，无法删除
		if (nullptr == pCur)
			return false;

		/* 四种情况：
		1.叶子节点----------->直接删除
		2.只有左孩子--------->直接删除
		3.只有右孩子--------->直接删除
		4.左右孩子均存在----->找一个替代节点替换之后，删除替代结点的原位置;
		*/

		//左子树为空(只有右子树)和叶子结点的情况
		if (pCur->left == nullptr)
		{
			if (root == pCur)
				root = pCur->right;

			//pCur是pParent的左子树时
			if (pCur == pParent->left)
				pParent->left = pCur->right;
			//pCur是pParent的右子树时
			else
				pParent->right = pCur->right;
		}
		//右子树为空(只有左孩子)的情况
		else if (pCur->right == nullptr)
		{
			if (root == pCur)
				root = pCur->left;

			//pCur是pParent的左子树时
			if (pCur == root->left)
				pParent->left = pCur->left;
			//pCur是pParent的右子树时
			else
				pParent->right = pCur->left;
		}
		//左右子树都不为空
		else
		{
			//找替代结点
			//替代节点：在左子树找最大或者在右子树找最小，这样替代结点替代被删除结点之后，树的结构不会改变
			//左子树中的最大结点
			PNode pFirstOfIn = pCur->left;
			pParent = pCur;
			while (pFirstOfIn->right)
			{
				pParent = pFirstOfIn;
				pFirstOfIn = pFirstOfIn->right;
			}
			pCur->val = pFirstOfIn->val;//进行替换
			if (pFirstOfIn == pParent->left)
				pParent->left = pFirstOfIn->right;
			else
				pParent->right = pFirstOfIn->right;
			pCur = pFirstOfIn;

			//右子树中的最小结点
			//PNode pLastOfIn = pCur->right;
			//while (pCur->left)
			//{
			//	pParent = pLastOfIn;
			//	pLastOfIn = pLastOfIn->left;
			//}
			//pCur->_data = pFirstOfIn->_data;//进行替换
			//if (pFirstOfIn == pParent->left)
			//	pParent->left = pFirstOfIn->left;
			//else
			//	pParent->right = pFirstOfIn->left;
			//pCur = pFirstOfIn;
		}

		delete pCur;
		//pCur = nullptr;

		return true;
#endif
	}
	//查找PNode Find(const T& data)
	PNode find(const T& data)
	{
		if (root == nullptr)
			return nullptr;
		PNode temp = root;
		while (temp)
		{
			if (temp->val == data)
				break;
			else if (temp->val > data)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return temp;
	}
	//中序遍历void InOrder()
	void InOrder()
	{
		_inorder(root);
	}
	//最小元素PNode LeftMost()
	PNode LeftMost()
	{
		if (root == nullptr)
			return root;
		PNode temp = root;
		while (temp->left)
			temp = temp->left;
		return temp;
	}
	//最大元素PNode RightMost()
	PNode RightMost()
	{
		if (root == nullptr)
			return root;
		PNode temp = root;
		while (temp->right)
			temp = temp->right;
		return temp;
	}
	~BSTree()
	{
		_Realease(root);
	}
private:
	void _inorder(PNode _root)
	{
		if (_root)
		{
			_inorder(_root->left);
			cout << _root->val;
			_inorder(_root->right);
		}
	}
	void _Realease(PNode& _root)
	{
		if (_root)
		{
			_Realease(_root->left);
			_Realease(_root->right);
			delete _root;
		}
	}
};

int main()
{
	vector<int> arr{8,4,11,3,6,9,12,1,2,5,7,14,10};
	BSTree<int> root;
	for (auto c : arr)
		root.Insert(c);
	root.Erase(2);
	return 0;
}