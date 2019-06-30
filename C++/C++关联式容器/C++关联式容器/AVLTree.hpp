#pragma once
#include<iostream>
using namespace std;

//AVL树是一个平衡的二叉搜索树，平衡因子的绝对值小于等于1；

//AVL树结点结构
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode(const pair<K,V>& data)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _bf(0)
	{}

	struct AVLTreeNode<K,V>* _pLeft;		//左子树
	struct AVLTreeNode<K,V>* _pRight;		//右子树
	struct AVLTreeNode<K, V>* _pParent;	    //双亲结点
	pair<K,V> _data;						//元素
	int _bf;							    //平衡因子
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K,V> Node;
	typedef Node* PNode;
public:
	AVLTree()
		:_pRoot(nullptr)
	{}
	~AVLTree()
	{
		_Destroy(_pRoot);
	}
	bool Insert(const pair<K,V>& data)
	{
		//空树--------直接插入
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		//非空
		PNode pCur = _pRoot;
		PNode pParent = nullptr;

		//先找到需要插入的位置
		while (pCur)
		{
			pParent = pCur;
			if (pCur->_data.first > data.first)
				pCur = pCur->_pLeft;
			else if (pCur->_data.first < data.first)
				pCur = pCur->_pRight;
			else
				return false;
		}

		//插入元素
		pCur = new Node(data);
		if (pCur->_data.first > pParent->_data.first)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;
		pCur->_pParent = pParent;

		//更新平衡因子
		while (pParent)
		{
			//更新插入结点的双亲的平衡因子
			if (pParent->_pLeft == pCur)
				pParent->_bf--;
			else
				pParent->_bf++;

			if (0 == pParent->_bf) //当更新后平衡因子为0时，不需要向上更新平衡因子
				break;
			else if (1 == pParent->_bf || -1 == pParent->_bf) //平衡因子为+-1时，循环向上进新平衡因子的更新
			{
				pCur = pParent;
				pParent = pCur->_pParent;
				//pParent = pParent->_pRarent;和上边这个语句等价
			}
			else //当更新后平衡因子为+-2时，要进行旋转
			{
				//现在双亲的平衡因子已经变成正负2
				if (2 == pParent->_bf)
				{
					//进行左单旋
					if (1 == pCur->_bf)
						RotateL(pParent);
					//右左双旋
					else
						RotateRL(pParent);
				}
				if (-2 == pParent->_bf)
				{
					//进行右单旋
					if (-1 == pCur->_bf)
						RotateR(pParent);
					//左右双旋
					else
						RotateLR(pParent);
				}
				break;
			}
		}
		return true;
	}
	void InOrder()
	{
		_InOrder(_pRoot);
		cout << endl;
	}
	bool IsBalanceTree()
	{
		return _IsBalance(_pRoot,false);
	}
private:
	bool _IsBalance(PNode pRoot,bool insert)
	{
		if (nullptr == pRoot)
			return true;

		size_t leftHeight = _Height(pRoot->_pLeft);
		size_t rightHeight = _Height(pRoot->_pRight);
		int bf = rightHeight - leftHeight;
		if (insert)
			pRoot->_bf = bf;
		if ((abs(bf) > 1) || pRoot->_bf != bf)
			return false;

		return _IsBalance(pRoot->_pLeft,insert) && _IsBalance(pRoot->_pRight,insert);
	}
	size_t _Height(PNode pRoot)
	{
		if (pRoot == nullptr)
			return 0;
		
		size_t leftHeight = _Height(pRoot->_pLeft);
		size_t rightHeight = _Height(pRoot->_pRight);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	void _InOrder(PNode pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data.first << " ";
			_InOrder(pRoot->_pRight);
		}
	}
	void _Destroy(PNode pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	void RotateL(PNode pParent)
	{
		PNode pSubR = pParent->_pRight;
		PNode pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)//pSubRL有可能不存在（三个结点组成的右单支）
			pSubRL->_pParent = pParent;

		PNode pPParent = pParent->_pParent;//先将pParent的双亲结点保存下来，分析后再将其与pSubR链接起来
		pSubR->_pParent = pPParent;
		pSubR->_pLeft = pParent;
		pParent->_pParent = pSubR;

		//旋转前pParent为根节点
		if (nullptr == pPParent)
			_pRoot = pSubR;
		else
		{
			if (pPParent->_pLeft == pParent)//用来进行对pSubR作为双亲(pPParent)的左子树还是右子树的判断
				pPParent->_pLeft = pSubR;
			else
				pPParent->_pRight = pSubR;
		}

		//更新平衡因子
		//pSubR->_bf = pParent->_bf = 0;
		_IsBalance(pSubR->_pParent,true);
	}
	void RotateR(PNode pParent)
	{
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;

		//进行旋转，改变pParent和pSubL的指向
		pParent->_pLeft = pSubLR;
		if (pSubLR)//pSubLR有可能不存在,进行判断
			pSubLR->_pParent = pParent;

		pSubL->_pRight = pParent;
		PNode pPParent = pParent->_pParent;
		pSubL->_pParent = pPParent;
		pParent->_pParent = pSubL;

		//旋转前pParent为根节点
		if (nullptr == pPParent)
			_pRoot = pSubL;
		else
		{
			if (pPParent->_pLeft == pParent)//用来进行对pSubL作为双亲(pPParent)左子树还是右子树的判断
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}

		//更新平衡因子
		//pParent->_bf = pSubL->_bf = 0;
		_IsBalance(pSubL->_pParent,true);
	}
	void RotateLR(PNode pParent)
	{
		RotateL(pParent->_pLeft);
		RotateR(pParent);
	}
	void RotateRL(PNode pParent)
	{
		RotateR(pParent->_pRight);
		RotateL(pParent);
	}
	//特殊情况下的RotateLR和RotateRL
	void RotateLR_special(PNode pParent)
	{
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;
		int bf = pSubLR->_bf;

		RotateL(pParent->_pLeft);
		RotateR(pParent);

		if (1 == bf)
			pSubL->_bf = -1;
		else if (-1 == bf)
			pParent->_bf = 1;
	}
	void RotateRL_special(PNode pParent)
	{
		PNode pSubR = pParent->_pRight;
		PNode pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;

		RotateR(pParent->_pRight);
		RotateL(pParent);
		if (1 == bf)
			pParent->_bf = -1;
		else if (-1 == bf)
			pSubR->_bf = 1;
		
	}
private:
	PNode _pRoot;
};

void TestAVLTree()
{
	//普通情况
	//int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//特殊情况
	int array[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
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