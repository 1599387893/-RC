#include<iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		:_pleft(nullptr)
		, _pright(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _bf(0)
	{}

	AVLTreeNode<T>* _pleft;
	AVLTreeNode<T>* _pright;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;
};

bool insert(const T& data)
{
	if (nullptr == _pRoot)
	{
		_pRoot = new Node(data);
		return true;
	}
	pNode pCur = _pRoot;
	PNode pParent = nullptr;
	while (pCur)
	{
		pParent = pCur;
		if (data < pCur->data)
			pCur = pCur->_pleft;
		else if (data > pCur->data)
			pCur = pCur->data;
		else
			return false;
	}
	if (data < pParent->data)
		pParent->_pleft = pCur;
	else
		pParent->_pright = pCur;

	pCur->_pParent = pParent;

	return true;
}