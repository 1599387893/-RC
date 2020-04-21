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

		//��ת֮ǰ������pSubLR��ƽ�����ӣ���ת��ɺ���Ҫ���ݸ�ƽ�����������������ڵ��ƽ������
		int bf = pSubLR->_bf;

		//�ȶԽϸ���������������
		RotateL(pParent->_pLeft);
		//�ڶ�pParent�ڵ�����ҵ���
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
		//������ڵ�Ϊ��
		if (_pRoot == nullptr)
		{
			_pRoot = new TreeNoe(data);
			return true;
		}
		//1.�Ƚ��ڵ㰴�ն����������Ĳ��뷽ʽ�����뵽����
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
		//2.����ƽ������
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
				//���ϸ���
				pCur = pParent;
				pParent = pParent->_pParent;
			}
			else //��ʱ��Ҫ��ת ����ʱpParent��ƽ������Ϊ2����-2
			{
				if (2 == pParent->_bf)//�������ϸ�
				{
					//��������
					if (pParent->_pRight->_bf == 1)
						RotateL(pParent);
					//����������
					else
						RotateRL(pParent);
				}
				if (-2 == pParent->_bf)//�������ϸ�
				{
					//�����ҵ���
					if (pParent->_pLeft->_bf == -1)
						RotateR(pParent);
					//�������ҵ���
					else
						RotateLR(pParent);
				}
				break;
			}
		}
		return true;
	}

};