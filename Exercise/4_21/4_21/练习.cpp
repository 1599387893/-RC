#include<iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _bf(0)
	{}
	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> TreeNode;
	typedef TreeNode* PNode;
private:
	PNode<T> _pRoot;
private:
	void RotateL(PNode pParent)
	{

	}
	void RotateR(PNode pParent)
	{
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;

		pSubLR->_pParent = pParent;
		pParent->_pLeft = pSubLR;
		pSubL->_pParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		if (pSubL->_pParent == nullptr)
		{
			_pRoot = pSubL;
			pSubL->_pParent = nullptr;
		}
		else if (pSubL->_pParent->_pLeft == pParent)
			pSubL->_pParent->_pLeft = pSubL;
		else
			pSubL->_pParent->_pRight = pSubL;
		pParent->_bf = pSubL->_bf = 0;
	}
	void RotateLR(PNode pParent)
	{
		PNode pSubL = pParent->_pLeft;
		PNode pSunLR = pSubL->_pRight;

		//旋转之前，保存pSubLR的平衡因子，旋转完成后，需要根据该平衡因子来调节其他节点的平衡因子
		int bf = pSubLR->_bf;

		//先对较高左子树进行左单旋
		RotateL(pParent->_pLeft);
		//在对pParent节点进行右单旋
		RotateR(pParent);

		if (1 == bf)
			pSubL->_bf = -1;
		else if (-1 == bf)
			pParent->_bf = 1;
	}
	void RotateRL(PNode pParent)
	{

	}
public:
	bool Insert(const T& data)
	{
		//如果根节点为空
		if (_pRoot == nullptr)
		{
			_pRoot = new TreeNoe(data);
			return true;
		}
		//1.先将节点按照二叉搜索树的插入方式，插入到树中
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (pCur->_data == data)
				return false;
			else if (pCur->_data > data)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}
		pCur = new TreeNode(data);
		if (pParent->_data > data)
			pParent->_pLeft = pCur ;
		else
			pParent->_pParent = pCur;
		pCur->_pParent = pParent;
		//2.更新平衡因子
		while (pParent)
		{
			if (pCur == pParent->_pLeft)
				pParent->_bf--;
			else
				pParent->_bf++;
			
			if (0 == pParent->_bf)
				break;
			else if (pParent->_bf == 1 || pParent->_bf == -1)
			{
				//向上更新
				pCur = pParent;
				pParent = pParent->_pParent;
			}
			else //此时需要旋转 即此时pParent的平衡因子为2或者-2
			{
				if (2 == pParent->_bf)//右子树较高
				{
					//进行左单旋
					if (pParent->_pRight->_bf == 1)
						RotateL(pParent);
					//进行右左单旋
					else
						RotateRL(pParent);
				}
				if (-2 == pParent->_bf)//左子树较高
				{
					//进行右单旋
					if (pParent->_pLeft->_bf == -1)
						RotateR(pParent);
					//进行左右单旋
					else
						RotateLR(pParent);
				}
				break;
			}
		}
		return true;
	}

};