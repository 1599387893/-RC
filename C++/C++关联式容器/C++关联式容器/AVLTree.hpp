#include<iostream>
using namespace std;

//AVL树结点结构
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

	struct AVLTreeNode<T>* _pLeft;		//左子树
	struct AVLTreeNode<T>* _pRight;		//右子树
	struct AVLTreeNode<T>* _pParent;	//双亲结点
	T _data;
	int _bf;							//平衡因子
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
	typedef Node* PNode;
public:
	bool Insert(const T& data)
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
			if (pCur->_data > data)
				pCur = pCur->_pLeft;
			else if (pCur->_data < data)
				pCur = pCur->_pRight;
			else
				return false;
		}
		//插入元素
		pCur = new Node(data);
		if (pCur->_data > pParent->_data)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;
		//更新平衡因子

	}
private:
	PNode _pRoot;
};