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
		
		//���ҵ���Ҫ�����λ��
		//����Ԫ��
		//����ƽ������
	}
private:
	PNode _pRoot;
};