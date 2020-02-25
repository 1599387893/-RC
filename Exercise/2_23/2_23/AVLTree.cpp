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
		//�ҵ�����λ�ã�
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
		//����ڵ㣻
		if (parent->val.first > data.first)
			parent->left = temp;
		else
			parent->right = temp;
		temp->parent = parent;
		//����ƽ������(�ӵ����ϸ���)
		while (parent)
		{
			//�Ƚ���ӽڵ�ĸ��ڵ��ƽ�����Ӹ���
			if (parent->left == temp)
				parent->_bf--;
			else
				parent->bf++;
			
			if (parent->_bf == 0) //�½��ĸ��ڵ��ƽ������Ϊ0������Ҫ���ϸ���
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)//�½��ĸ��ڵ��ƽ������Ϊ+-1ʱ���ø��ڵ㲻��Ҫ��ת������ѭ��
				parent = parent->parent;
			else //ƽ������Ϊ+-2ʱ��Ҫ������ת
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

		//�����߶�
	}
	void Inorder()
	{
		_inorder(_root);
	}
	bool IsBalanceTree(){}
};