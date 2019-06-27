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
	T* _val;
	Color _color;
};

template<class T>
class BRTree
{
	typedef RBTreeNode<T> Node;
	typedef Node* PNode;

public:
	BRTree()
		:_pHead(new PNode)
	{
		_pHead->_pParent = nullptr;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}
	PNode& GetRoot()
	{
		return _pHead->_pParent;
	}

	//���Ĳ���
	bool insert(const T& data)
	{
		PNode pRoot = GetRoot();
		//���Ϊ����
		if (pRoot->_pParent == nullptr)
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
			Node pNewNode = new Node(data);
			if (data >pParent->_val)
				pParent->_pParent = pCur;
			else
				pParent->_pLeft = pCur;
			pCur->_pParent = pParent;

			//�޸���ɫ 
		}
	}
private:
	PNode _pHead;
};


