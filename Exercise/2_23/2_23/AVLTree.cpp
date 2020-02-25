#pragma once

#include<iostream>
#include<vector>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	int _bf;
	pair<K,V> val;
	struct AVLTreeNode<K,V>* left;
	struct AVLTreeNode<K,V>* right;
	struct AVLTreeNode<K, V>* parent;
	AVLTreeNode(const pair<K,V>& data)
		:val(data)
		, left(nullptr)
		, right(nullptr)
		, parent(nullptr)
		, _bf(0)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef struct AVLTreeNode<K,V> Node;
	typedef Node* PNode;
private:
	PNode _root;
public:
	AVLTree()
		_root(nullptr)
	{}
	~AVLTree()
	{}
	void Insert(const pair<K, V>& data)
	{
		//找到插入位置；
		if (_root == nullptr)
			_root = new Node(data);
		PNode parent = _root;
		PNode temp = _root;
		while (temp)
		{
			parent = temp;
			if (data.first > temp->val.first)
				temp = temp->right;
			if (data.frist < temp->val.first)
				temp = temp->left;
		}
		temp = new Node(data);
		//插入节点；
		if (parent->val.first > data.first)
			parent->left = temp;
		else
			parent->right = temp;
		temp->parent = parent;
		//更新平衡因子(从底向上更新)
		while (parent)
		{
			//先将添加节点的父节点的平衡因子更新
			if (parent->left == temp)
				parent->_bf--;
			else
				parent->bf++;
			
			if (parent->_bf == 0) //新结点的父节点的平衡因子为0，不需要向上更新
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)//新结点的父节点的平衡因子为+-1时，该父节点不需要旋转，向上循环
				parent = parent->parent;
			else //平衡因子为+-2时，要进行旋转
			{
				if (parent->_bf == 2)
				{
					if (parent->)
				}
				else
				{

				}
			}

		}

		//调整高度
	}
	void Inorder()
	{
		_inorder(_root);
	}
	bool IsBalanceTree(){}
};