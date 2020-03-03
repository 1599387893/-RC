#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#pragma once

template<class K, class V>
struct AVLTreeNode
{
	struct AVLTreeNode<K, V>* pleft;
	struct AVLTreeNode<K, V>* pright;
	struct AVLTreeNode<K, V>* pparent;
	pair<K,V> data;
	int _bf;

	AVLTreeNode(const pair<K, V>& _data)
		: pleft(nullptr)
		, pright(nullptr)
		, pparent(nullptr)
		, _bf(0)
		, data(_data)
	{}
	
};

template<class K, class V>
class AVLTree
{
	typedef struct AVLTreeNode<K, V> Node;
	typedef Node* PNode;
public:
	AVLTree()
		:_root(nullptr){}
	bool Insert(const pair<K,V>& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			return true;
		}
		//先找到插入位置
		PNode pCur = _root;
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (pCur->data.first == data.first)
				return false;
			else if (pCur->data.first > data.first)
				pCur = pCur->pleft;
			else
				pCur = pCur->pright;
		}
		pCur = new Node(data);
		//插入元素
		if (pParent->data.first > data.first)
			pParent->pleft = pCur;
		else
			pParent->pright = pCur;
		pCur->pparent = pParent;
		//更新平衡因子
			//平衡银子的更新要从插入位置的父节点开始更新；
		while (pParent)
		{
			if (pParent->pleft == pCur)
				pParent->_bf--;
			else
				pParent->_bf++;
			//1.如果pParent的平衡因子为0，不需要向上更新；
			//2.如果pParent的平衡因子为+-1，继续向上循环更新；
			//3. 如果pParent的平衡因子为+-2，就需要进行旋转，控制平衡因子；
			if (pParent->_bf == 0)
				break;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
			{
				pCur = pParent;
				pParent = pCur->pparent;
			}
			else
			{
				if (pParent->_bf == 2)
				{
					if (pParent->pright->_bf == 1)
						RotateL(pParent);
					else
						RotateRL(pParent);
				}
				else
				{
					if (pParent->pleft->_bf == -1)
						RotateR(pParent);
					else
						RotateLR(pParent);
				}
			}
		}
		return true;
	}
	void InOrder()
	{
		_inorder(_root);
		cout << endl;
	}
	bool IsBalanceTree()
	{
		return _IsBTree(_root,false);
	}
	~AVLTree(){
		_Destory(_root);
	}
private:
	void _inorder(PNode root)
	{
		if (root)
		{
			_inorder(root->pleft);
			cout << root->data.first << endl;
			_inorder(root->pright);
		}
	}
	size_t Heigh(PNode root)
	{
		if (root == nullptr)
			return 0;
		else if (root->pleft == nullptr && root->pright == nullptr)
			return 1;
		else
			return 1+max(Heigh(root->pleft),Heigh(root->pright));
	}
	bool _IsBTree(PNode root,bool insert)
	{
		if ((root == nullptr) || (root->pleft==nullptr && root->pright==nullptr))
			return true;
		int left = Heigh(root->pleft);
		int right = Heigh(root->pright);
		int bf = right-left;
		if (insert)
			root->_bf = bf;
		if (abs(bf) > 1 || root->_bf != bf)
			return false;
		return _IsBTree(root->pleft,insert) && _IsBTree(root->pright,insert);
	}
	void _Destory(PNode root)
	{
		if (_root)
		{
			_Destory(root->pleft);
			_Destory(root->pright);
			delete root;
		}
	}
private:
	void RotateL(PNode root)
	{
		//
		PNode pParent = root->pparent;
		PNode pRight = root->pright;
		pRight->pparent = pParent;
		if (pParent!=nullptr && pParent->pleft == root)
			pParent->pleft = pRight;
		else if (pParent != nullptr && pParent->pright == root)
			pParent->pright = pRight;
		else
			_root = pRight;
		root->pright = pRight->pleft;
		if (pRight->pleft)
			pRight->pleft->pparent = root;
		pRight->pleft = root;
		root->pparent = pRight;

		/*
		1.
		root->_bf = 0;
		pRight->_bf = 0;
		pRight->pright->_bf = 1;
		*/
		//2.
		_IsBTree(pRight->pparent,true);
	}
	void RotateR(PNode root)
	{
		//
		PNode pSubL = root->pleft;
		PNode pParent = root->pparent;
		PNode pSubLR = pSubL->pright;
		pSubL->pparent = pParent;
		if (pParent != nullptr && pParent->pleft == root)
			pParent->pleft = pSubL;
		if (pParent != nullptr && pParent->pright == root)
			pParent->pright = pSubL;
		if (pSubLR)
			pSubLR->pparent = root;
		root->pleft = pSubLR;
		pSubL->pright = root;
		root->pparent = pSubL;

		_IsBTree(pSubL->pparent,true);
	}
	void RotateLR(PNode root)
	{
		//xianzuodanxuan ;zaiyouduanxuan 
		RotateL(root->pleft);
		RotateR(root);
	}
	void RotateRL(PNode root)
	{
		RotateR(root->pright);
		RotateL(root);
	}
private:
	PNode _root;
};

int main()
{
	//普通情况
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//特殊情况
	//int array[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> tree;
	/*for (auto e : array)
	tree.Insert(make_pair(e, e));*/
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		tree.Insert(make_pair(array[i], array[i]));

	tree.InOrder();
	if (tree.IsBalanceTree())
		cout << "tree is AVLTree" << endl;
	else
		cout << "tree is not AVLTree" << endl;
}