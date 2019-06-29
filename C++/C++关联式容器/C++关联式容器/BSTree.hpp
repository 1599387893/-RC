#pragma once
#include<iostream>
using namespace std;

//BSTree是二叉搜索树，任一结点的左子树中的元素都小于该节点，其右子树中的元素都大于该结点；

template<class  T>
struct BSTreeNode
{
	BSTreeNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _data(data)
	{}
	struct BSTreeNode<T>* _pLeft;
	struct BSTreeNode<T>* _pRight;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTreeNode<T> Node;
	typedef Node* PNode;
public:
	//构造函数
	BSTree()
		:_pRoot(nullptr)
	{}
	//析构函数
	~BSTree()
	{
		_Destroy(_pRoot);
	}
	//插入元素
	bool Insert(const T& data)
	{
		//空树------------直接插入
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		//非空
		//1.先找到需要插入的位置
		PNode pCur = _pRoot;
		PNode pParent = nullptr;

		//如果可以找到位置，那么该位置一定是叶子节点
		while (pCur)
		{
			pParent = pCur;
			if (data > pCur->_data)
				pCur = pCur->_pRight;
			else if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else
				return false;
		}
		pCur = new Node(data);

		//2.插入元素
		//判断插入叶子节点的左子树还是右子树
		if (pCur->_data > pParent->_data)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;

		return true;
	}
	//删除元素
	bool Erase(const T& data)
	{
		//空树
		if (_pRoot == nullptr)
			return false;
		//非空
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		
		//1.查找data在树中的位置
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if (data > pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
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
		if (pCur->_pLeft == nullptr)
		{
			if (_pRoot == pCur)
				_pRoot = pCur->_pRight;

			//pCur是pParent的左子树时
			if (pCur == pParent->_pLeft)
				pParent->_pLeft = pCur->_pRight;
			//pCur是pParent的右子树时
			else
				pParent->_pRight = pCur->_pRight;
		}
		//右子树为空(只有左孩子)的情况
		else if (pCur->_pRight == nullptr)
		{
			if (_pRoot == pCur)
				_pRoot = pCur->_pLeft;

			//pCur是pParent的左子树时
			if (pCur == _pRoot->_pLeft)
				pParent->_pLeft = pCur->_pLeft;
			//pCur是pParent的右子树时
			else
				pParent->_pRight = pCur->_pLeft;
		}
		//左右子树都不为空
		else
		{
			//找替代结点
			//替代节点：在左子树找最大或者在右子树找最小，这样替代结点替代被删除结点之后，树的结构不会改变
			//左子树中的最大结点
			PNode pFirstOfIn = pCur->_pLeft;
			pParent = pCur;
			while (pFirstOfIn->_pRight)
			{
				pParent = pFirstOfIn;
				pFirstOfIn = pFirstOfIn->_pRight;
			}
			pCur->_data = pFirstOfIn->_data;//进行替换
			if (pFirstOfIn == pParent->_pLeft)
				pParent->_pLeft = pFirstOfIn->_pRight;
			else
				pParent->_pRight = pFirstOfIn->_pRight;
			pCur = pFirstOfIn;

			//右子树中的最小结点
			//PNode pLastOfIn = pCur->_pRight;
			//while (pCur->_pLeft)
			//{
			//	pParent = pLastOfIn;
			//	pLastOfIn = pLastOfIn->_pLeft;
			//}
			//pCur->_data = pFirstOfIn->_data;//进行替换
			//if (pFirstOfIn == pParent->_pLeft)
			//	pParent->_pLeft = pFirstOfIn->_pLeft;
			//else
			//	pParent->_pRight = pFirstOfIn->_pLeft;
			//pCur = pFirstOfIn;
		}

		delete pCur;
		//pCur = nullptr;

		return true;
	}
	//查找元素
	PNode Find(const T& data)
	{
		if (nullptr == _pRoot)
			return _pRoot;
		
		PNode pCur = _pRoot;

		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;
			else if (pCur->_data > data)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}

		return nullptr;
	}
	//中序遍历
	void InOrder()
	{
		_inOrder(_pRoot);
		cout << endl;
	}
	//二叉搜索树中的最小元素
	PNode LeftMost()
	{
		if (nullptr == _pRoot)
			return nullptr;

		PNode pCur = _pRoot;
		while (pCur->_pLeft)
			pCur = pCur->_pLeft;
		return pCur;
	}
	//二叉搜索树中的最大元素
	PNode RightMost()
	{
		if (nullptr == _pRoot)
			return nullptr;

		PNode pCur = _pRoot;
		while (pCur->_pRight)
			pCur = pCur->_pRight;
		return pCur;
	}
private:
	void _inOrder(PNode pRoot)
	{
		if (pRoot)
		{
			_inOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_inOrder(pRoot->_pRight);
		}

	}
	void _Destroy(PNode& pRoot)
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
	PNode _pRoot;
};

void TestBSTree()
{
	BSTree<int> pRoot;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto& e : a)
		pRoot.Insert(e);

	cout << pRoot.LeftMost()->_data << endl;
	cout << pRoot.RightMost()->_data << endl;

	cout << pRoot.Find(5)->_data << endl;
	pRoot.InOrder();
	pRoot.Erase(5);
	pRoot.InOrder();
	cout << pRoot.Find(6)->_data << endl;
	pRoot.~BSTree();

}