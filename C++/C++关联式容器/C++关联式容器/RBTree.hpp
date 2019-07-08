#include<iostream>
using namespace std;
enum Color{ RED, BLACK };

//红黑树结点结构
template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), Color color = RED)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _val(data)
		, _color(color)
	{}

	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	T _val;
	Color _color;
};

template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
	 typedef Node* PNode;

public:
	RBTree()
		:_pHead(new Node)
	{
		_pHead->_pParent = nullptr;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}
	PNode& GetRoot()
	{
		return _pHead->_pParent;
	}
	void RotateL(PNode pParent)
	{
		PNode pSubR = pParent->_pRight;
		PNode pSubRL = pSubR->_pLeft;

		//pParent和pSubRL的关系
		pParent->_pRight = pSubRL;
		if (pSubRL)//有可能存在右单支的情况
			pSubRL->_pParent = pParent;
		
		//pSubR和pPParent的关系
		PNode pPParent = pParent->_pParent;
		pSubR->_pParent = pPParent;
		if (pPParent == _pHead)
		{
			_pHead->_pParent = pSubR;
		}
		else
		{
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubR;
			else
				pPParent->_pRight = pSubR;
		}

		//pSubR和pParent的关系
		pSubR->_pLeft = pParent;
		pParent->_pParent = pSubR;

	}
	void RotateR(PNode pParent)
	{
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;

		pParent->_pRight = pSubLR;
		if (pSubLR)
			pSubLR->_pParent = pParent;
		
		PNode pPParent = pParent->_pParent;
		pSubL->_pParent = pPParent;
		if (pPParent == _pHead)
		{
			_pHead->_pParent = pSubL;
		}
		else
		{
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}

		pSubL->_pRight = pParent;
		pParent->_pParent = pSubL;
	}
	//结点的插入
	bool insert(const T& data)
	{
		PNode pRoot = GetRoot();
		//如果为空树
		if (pRoot == nullptr)
		{
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
		}
		//红黑树不为空
		else
		{
			//先找到要插入的位置
			PNode pCur = _pHead->_pParent;//PNode pCur = pRoot;
			PNode pParent = nullptr;
			while (pCur)
			{
				if (pCur->_val > data)
					pCur = pCur->_pLeft;
				else if (pCur->_val < data)
					pCur = pCur->_pRight;
				else
					return false;
			}
			pParent = pCur->_pParent;
			//进行插入
			PNode pNewNode = new Node(data);
			if (data >pParent->_val)
				pParent->_pParent = pCur;
			else
				pParent->_pLeft = pCur;
			pCur->_pParent = pParent;

			//修改颜色 
			while (pParent != _pHead && RED == pParent->_color)
			{
				PNode grandFather = pParent->_pParent;
				if (pParent == grandFather->_pLeft)//叔叔结点在左边
				{
					PNode uncle = grandFather->_pRight;
					//情况一:叔叔节点存在且为红
					if (uncle && RED == uncle->_color)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						pCur = grandFather;
						pParent = pCur->_pParent;
					}
					else
					{
						//情况三：pCur是pParent的右孩子，叔叔结点可能不存在 || 叔叔结点存在且位黑
						if (pCur == pParent->_pLeft)
						{
							RotateL(pParent);
							swap(pParent, pCur);
						}
						//情况二
						grandFather->_color = RED;
						pParent->_color = BLACK;
						RotateR(grandFather);
					}
				}
				else//叔叔结点在右边
				{
					PNode uncle = grandFather->_pLeft;
					if (uncle && RED == uncle->_color)//情况一
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						pCur = grandFather;
						pParent = pCur->_pParent;
					}
					else//情况三
					{
						if (pCur == pParent->_pLeft)
						{
							RotateR(pParent);
							swap(pParent, pCur);
						}
						pParent->_color = BLACK;
						grandFather->_color = RED;
						RotateL(grandFather);
					}
				}
			}
		}
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		pRoot->_color = BLACK; 

		return true;
	}
	void Inorder()
	{
		_InOrder(_pHead);
		cout << endl;
	}
private:
	PNode LeftMost()
	{
		PNode pCur = GetRoot();
		if (nullptr == pCur)
			return _pHead;

		while (pCur->_pLeft)
			pCur = pCur->_pLeft;

		return pCur;
	}
	PNode RightMost()
	{
		PNode pCur = GetRoot();
		if (nullptr == pCur)
			return _pHead;

		while (pCur->_pRight)
			pCur = pCur->_pRight;

		return pCur;
	}
	void _InOrder(PNode pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_val << " ";
			_InOrder(pRoot->_pRight);
		}
	}
private:
	PNode _pHead;
};

void TestRBTree()
{
	int array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> rbt;
	for (auto& e : array)
		rbt.insert(e);

	rbt.Inorder();


}


//01:17:44


