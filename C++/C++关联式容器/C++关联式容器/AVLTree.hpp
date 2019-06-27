#include<iostream>
using namespace std;

//AVL�����ṹ
template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pRarent(nullptr)
		, _data(data)
		, _bf(0)
	{}

	struct AVLTreeNode<T>* _pLeft;		//������
	struct AVLTreeNode<T>* _pRight;		//������
	struct AVLTreeNode<T>* _pParent;	//˫�׽��
	T _data;
	int _bf;							//ƽ������
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
	typedef Node* PNode;
public:
	bool Insert(const T& data)
	{
		//����--------ֱ�Ӳ���
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		//�ǿ�
		PNode pCur = _pRoot;
		PNode pParent = nullptr;

		//���ҵ���Ҫ�����λ��
		while (pCur)
		{
			pParent = pCur;
			if (pCur->_data > data)
				pCur = pCur->_pLeft;
			else if (pCur->_data < data)
				pCur = pCur->_pRight;
			else
				return false;
		}
		//����Ԫ��
		pCur = new Node(data);
		if (pCur->_data > pParent->_data)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;
		//����ƽ������

	}
private:
	PNode _pRoot;
};