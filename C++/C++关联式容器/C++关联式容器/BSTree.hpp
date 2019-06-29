#pragma once
#include<iostream>
using namespace std;

//BSTree�Ƕ�������������һ�����������е�Ԫ�ض�С�ڸýڵ㣬���������е�Ԫ�ض����ڸý�㣻

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
	//���캯��
	BSTree()
		:_pRoot(nullptr)
	{}
	//��������
	~BSTree()
	{
		_Destroy(_pRoot);
	}
	//����Ԫ��
	bool Insert(const T& data)
	{
		//����------------ֱ�Ӳ���
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		//�ǿ�
		//1.���ҵ���Ҫ�����λ��
		PNode pCur = _pRoot;
		PNode pParent = nullptr;

		//��������ҵ�λ�ã���ô��λ��һ����Ҷ�ӽڵ�
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

		//2.����Ԫ��
		//�жϲ���Ҷ�ӽڵ������������������
		if (pCur->_data > pParent->_data)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;

		return true;
	}
	//ɾ��Ԫ��
	bool Erase(const T& data)
	{
		//����
		if (_pRoot == nullptr)
			return false;
		//�ǿ�
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		
		//1.����data�����е�λ��
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
		//data���ڶ������У��޷�ɾ��
		if (nullptr == pCur)
			return false;
		
		/* ���������
		1.Ҷ�ӽڵ�----------->ֱ��ɾ��
		2.ֻ������--------->ֱ��ɾ��
		3.ֻ���Һ���--------->ֱ��ɾ��
		4.���Һ��Ӿ�����----->��һ������ڵ��滻֮��ɾ���������ԭλ��;
		*/
		
		//������Ϊ��(ֻ��������)��Ҷ�ӽ������
		if (pCur->_pLeft == nullptr)
		{
			if (_pRoot == pCur)
				_pRoot = pCur->_pRight;

			//pCur��pParent��������ʱ
			if (pCur == pParent->_pLeft)
				pParent->_pLeft = pCur->_pRight;
			//pCur��pParent��������ʱ
			else
				pParent->_pRight = pCur->_pRight;
		}
		//������Ϊ��(ֻ������)�����
		else if (pCur->_pRight == nullptr)
		{
			if (_pRoot == pCur)
				_pRoot = pCur->_pLeft;

			//pCur��pParent��������ʱ
			if (pCur == _pRoot->_pLeft)
				pParent->_pLeft = pCur->_pLeft;
			//pCur��pParent��������ʱ
			else
				pParent->_pRight = pCur->_pLeft;
		}
		//������������Ϊ��
		else
		{
			//��������
			//����ڵ㣺����������������������������С�����������������ɾ�����֮�����Ľṹ����ı�
			//�������е������
			PNode pFirstOfIn = pCur->_pLeft;
			pParent = pCur;
			while (pFirstOfIn->_pRight)
			{
				pParent = pFirstOfIn;
				pFirstOfIn = pFirstOfIn->_pRight;
			}
			pCur->_data = pFirstOfIn->_data;//�����滻
			if (pFirstOfIn == pParent->_pLeft)
				pParent->_pLeft = pFirstOfIn->_pRight;
			else
				pParent->_pRight = pFirstOfIn->_pRight;
			pCur = pFirstOfIn;

			//�������е���С���
			//PNode pLastOfIn = pCur->_pRight;
			//while (pCur->_pLeft)
			//{
			//	pParent = pLastOfIn;
			//	pLastOfIn = pLastOfIn->_pLeft;
			//}
			//pCur->_data = pFirstOfIn->_data;//�����滻
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
	//����Ԫ��
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
	//�������
	void InOrder()
	{
		_inOrder(_pRoot);
		cout << endl;
	}
	//�����������е���СԪ��
	PNode LeftMost()
	{
		if (nullptr == _pRoot)
			return nullptr;

		PNode pCur = _pRoot;
		while (pCur->_pLeft)
			pCur = pCur->_pLeft;
		return pCur;
	}
	//�����������е����Ԫ��
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