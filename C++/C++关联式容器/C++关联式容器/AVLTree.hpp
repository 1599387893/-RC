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
		
		//先找到需要插入的位置
		//插入元素
		//更新平衡因子
	}
private:
	PNode _pRoot;
};