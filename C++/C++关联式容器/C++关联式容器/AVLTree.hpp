#pragma once
#include<iostream>
using namespace std;

//AVL����һ��ƽ��Ķ�����������ƽ�����ӵľ���ֵС�ڵ���1��

//AVL�����ṹ
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

	struct AVLTreeNode<K,V>* _pLeft;		//������
	struct AVLTreeNode<K,V>* _pRight;		//������
	struct AVLTreeNode<K, V>* _pParent;	    //˫�׽��
	pair<K,V> _data;						//Ԫ��
	int _bf;							    //ƽ������
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
		_Destroy();
	}
	bool Insert(const pair<K,V>& data)
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
			if (pCur->_data.first > data.first)
				pCur = pCur->_pLeft;
			else if (pCur->_data.first < data.first)
				pCur = pCur->_pRight;
			else
				return false;
		}

		//����Ԫ��
		pCur = new Node(data);
		if (pCur->_data.first > pParent->_data.first)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;
		pCur->_pParent = pParent;

		//����ƽ������
		while (pParent)
		{
			//���²������˫�׵�ƽ������
			if (pParent->_pLeft == pCur)
				pParent->_bf--;
			else
				pParent->_bf++;

			if (0 == pParent->_bf) //�����º�ƽ������Ϊ0ʱ������Ҫ���ϸ���ƽ������
				break;
			else if (1 == pParent->_bf || -1 == pParent->_bf) //ƽ������Ϊ+-1ʱ��ѭ�����Ͻ���ƽ�����ӵĸ���
			{
				pCur = pParent;
				pParent = pParent->_pParent;
			}
			else //�����º�ƽ������Ϊ+-2ʱ��Ҫ������ת
			{
				//����˫�׵�ƽ�������Ѿ��������2
				if (2 == pParent->_bf)
				{
					//��������
					if (1 == pCur->_bf)
						RotateL(pParent);
					//����˫��
					else
						RotateRL(pParent);
				}
				if (-2 == pParent->_bf)
				{
					//�����ҵ���
					if (-1 == pCur->_bf)
						RotateR(pParent);
					//����˫��
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
private:
	void _InOrder(PNode pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data.first << " ";
			_InOrder(pRoot->_pLeft);
		}
	}
	void _Destroy()
	{

	}
private:
	void RotateL(PNode pParent)
	{
		PNode pSubR = pParent->_pRight;
		PNode pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)//pSubRL�п��ܲ����ڣ����������ɵ��ҵ�֧��
			pSubRL->_pParent = pParent;

		PNode pPParent = pParent->_pParent;//�Ƚ�pParent��˫�׽�㱣���������������ٽ�����pSubR��������
		pSubR->_pParent = pPParent;
		pSubR->_pLeft = pParent;
		pParent->_pParent = pSubR;

		//��תǰpParentΪ���ڵ�
		if (nullptr == pPParent)
			_pRoot = pSubR;
		else
		{
			if (pPParent->_pLeft == pParent)//�������ж�pSubR��Ϊ˫��(pPParent)���������������������ж�
				pPParent->_pLeft = pSubR;
			else
				pPParent->_pRight = pSubR;
		}

		//����ƽ������
		pSubR->_bf = pParent->_bf = 0;
	}
	void RotateR(PNode pParent)
	{
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;

		//������ת���ı�pParent��pSubL��ָ��
		pParent->_pLeft = pSubLR;
		if (pSubLR)//pSubLR�п��ܲ�����,�����ж�
			pSubLR->_pParent = pParent;

		pSubL->_pRight = pParent;
		PNode pPParent = pParent->_pParent;
		pSubL->_pParent = pPParent;
		pParent->_pParent = pSubL;

		//��תǰpParentΪ���ڵ�
		if (nullptr == pPParent)
			_pRoot = pSubL;
		else
		{
			if (pPParent->_pLeft == pParent)//�������ж�pSubL��Ϊ˫��(pPParent)�������������������ж�
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}

		//����ƽ������
		pParent->_bf = pSubL->_bf = 0;
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
private:
	PNode _pRoot;
};

void TestAVLTree()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int, int> tree;
	/*for (auto e : array)
		tree.Insert(make_pair(e, e));*/
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		tree.Insert(make_pair(array[i], array[i]));

	tree.InOrder();

}