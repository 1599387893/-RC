#include<iostream>
using namespace std;
enum Color{ RED, BLACK };

//��������ṹ
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

		//pParent��pSubRL�Ĺ�ϵ
		pParent->_pRight = pSubRL;
		if (pSubRL)//�п��ܴ����ҵ�֧�����
			pSubRL->_pParent = pParent;
		
		//pSubR��pPParent�Ĺ�ϵ
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

		//pSubR��pParent�Ĺ�ϵ
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
	//���Ĳ���
	bool insert(const T& data)
	{
		PNode pRoot = GetRoot();
		//���Ϊ����
		if (pRoot == nullptr)
		{
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
		}
		//�������Ϊ��
		else
		{
			//���ҵ�Ҫ�����λ��
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
			//���в���
			PNode pNewNode = new Node(data);
			if (data >pParent->_val)
				pParent->_pParent = pCur;
			else
				pParent->_pLeft = pCur;
			pCur->_pParent = pParent;

			//�޸���ɫ 
			while (pParent != _pHead && RED == pParent->_color)
			{
				PNode grandFather = pParent->_pParent;
				if (pParent == grandFather->_pLeft)//�����������
				{
					PNode uncle = grandFather->_pRight;
					//���һ:����ڵ������Ϊ��
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
						//�������pCur��pParent���Һ��ӣ���������ܲ����� || �����������λ��
						if (pCur == pParent->_pLeft)
						{
							RotateL(pParent);
							swap(pParent, pCur);
						}
						//�����
						grandFather->_color = RED;
						pParent->_color = BLACK;
						RotateR(grandFather);
					}
				}
				else//���������ұ�
				{
					PNode uncle = grandFather->_pLeft;
					if (uncle && RED == uncle->_color)//���һ
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						pCur = grandFather;
						pParent = pCur->_pParent;
					}
					else//�����
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


