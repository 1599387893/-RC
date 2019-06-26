#include<iostream>
using namespace std;

template<class  T>
struct BSTreeNode
{
	BSTreeNode(const T& data)
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
	BSTree()
		:_pRoot(nullptr)
	{}
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
		
		//������Ϊ��
		if (pCur->_pLeft == nullptr)
		{
			//pCur��pParent��������ʱ
			if (pCur->_data < pParent->_data)
				pParent->_pLeft = pCur->_pRight;
			//pCur��pParent��������ʱ
			else
				pParent->_pRight = pCur->_pRight;
		}
		//������Ϊ��
		else if (pCur->_pRight == nullptr)
		{
			//pCur��pParent��������ʱ
			if (pCur->_data < pParent->_data)
				pParent->_pLeft = pCur->_pLeft;
			//pCur��pParent��������ʱ
			else
				pParent->_pRight = pCur->_pLeft;
		}
		//������������Ϊ��
		else
		{

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
		cout << endl;
	}
private:
	PNode _pRoot;
};

void TestBSTree()
{
	BSTree<int> pRoot;
	for (int i = 0; i < 10; ++i)
		pRoot.Insert(i);

	pRoot.InOrder();
	pRoot.Erase(5);
	pRoot.InOrder();
	cout << pRoot.Find(6)->_data << endl;
	
}