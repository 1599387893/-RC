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
	//插入元素
	bool Insert(const T& data)
	{
		//空树------------直接插入
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		//非空
		//1.先找到需要插入的位置
		PNode pCur = _pRoot;
		PNode pParent = nullptr;

		//如果可以找到位置，那么该位置一定是叶子节点
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

		//2.插入元素
		//判断插入叶子节点的左子树还是右子树
		if (pCur->_data > pParent->_data)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;

		return true;
	}
	//删除元素
	bool Erase(const T& data)
	{
		//空树
		if (_pRoot == nullptr)
			return false;
		//非空
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		
		//1.查找data在树中的位置
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
		//data不在二叉树中，无法删除
		if (nullptr == pCur)
			return false;
		
		//左子树为空
		if (pCur->_pLeft == nullptr)
		{
			//pCur是pParent的左子树时
			if (pCur->_data < pParent->_data)
				pParent->_pLeft = pCur->_pRight;
			//pCur是pParent的右子树时
			else
				pParent->_pRight = pCur->_pRight;
		}
		//右子树为空
		else if (pCur->_pRight == nullptr)
		{
			//pCur是pParent的左子树时
			if (pCur->_data < pParent->_data)
				pParent->_pLeft = pCur->_pLeft;
			//pCur是pParent的右子树时
			else
				pParent->_pRight = pCur->_pLeft;
		}
		//左右子树都不为空
		else
		{

		}

		delete pCur;
		//pCur = nullptr;

		return true;
	}
	//查找元素
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
	//中序遍历
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