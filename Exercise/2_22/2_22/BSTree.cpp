#pragma once

#include<iostream>
#include<vector>
using namespace std;
template<class T>
struct BSTreeNode
{
	T val;
	struct BSTreeNode<T>* left;
	struct BSTreeNode<T>* right;
	BSTreeNode(const T& _val)
		:val(_val)
		, left(nullptr)
		, right(nullptr)
	{}
};

template<class T>
class BSTree
{
	typedef struct BSTreeNode<T> Node;
	typedef Node* PNode;
private:
	PNode root;
public:
	BSTree() :root(nullptr)
	{}
	//����bool Insert(const T& data)
	bool Insert(const T& data)
	{
		if (root == nullptr)
		{
			root = new Node(data);
			return true;
		}
		//�ҵ�����λ��
		PNode temp = root;
		while (1)
		{
			if (temp->val == data)
				return false;
			if (temp->val > data)
			{
				if (temp->left == nullptr)
				{
					temp->left = new Node(data);
					return true;
				}
				else
					temp = temp->left;
			}
			if (temp->val < data)
			{
				if (temp->right == nullptr)
				{
					temp->right = new Node(data);
					return true;
				}
				else
					temp = temp->right;
			}
		}
	}
	//ɾ��bool Erase(const T& data)
	bool Erase(const T& data)
	{
		if (root == nullptr)
			return true;
		PNode pCur = root;
		PNode parent = nullptr;
		while (pCur)
		{
			if (pCur->val == data)
				break;
			parent = pCur;
			if (pCur->val > data)
				pCur = pCur->left;
			else
				pCur = pCur->right;
		}
		if (pCur == nullptr)
			return false;
		
		//1.ֻ��������--->ֱ��ɾ��
		//2.ֻ��������--->ֱ��ɾ��
		//3.����������������--->ֱ��ɾ��
		//4.��������������
		if (!pCur->right)
		{
			if (root == pCur)
				root = pCur->left;
			if (parent->left == pCur)
				parent->left = pCur->left;
			else
				parent->right = pCur->left;
			delete pCur;
		}
		else if (!pCur->left)
		{
			if (pCur == root)
				root = pCur->right;
			if (parent->left == pCur)
				parent->left = pCur->right;
			else
				parent->right = pCur->right;
			delete pCur;
		}
		else
		{
			//�ҳ�pCur�����������ģ�����pCur����������С�ģ���pCur�滻��
			PNode temp = pCur->left;
			parent = pCur;
			while (temp->right)
			{
				parent = temp;
				temp = temp->right;
			}
			pCur->val = temp->val;
			if (parent == pCur)
				pCur->left = nullptr;
			else
				parent->right = nullptr;
			delete temp;
		}
		return true;

#if 0

		//����
		if (root == nullptr)
			return false;
		//�ǿ�
		PNode pCur = root;
		PNode pParent = nullptr;

		//1.����data�����е�λ��
		while (pCur)
		{
			if (data == pCur->val)
				break;
			else if (data > pCur->val)
			{
				pParent = pCur;
				pCur = pCur->right;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->left;
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
		if (pCur->left == nullptr)
		{
			if (root == pCur)
				root = pCur->right;

			//pCur��pParent��������ʱ
			if (pCur == pParent->left)
				pParent->left = pCur->right;
			//pCur��pParent��������ʱ
			else
				pParent->right = pCur->right;
		}
		//������Ϊ��(ֻ������)�����
		else if (pCur->right == nullptr)
		{
			if (root == pCur)
				root = pCur->left;

			//pCur��pParent��������ʱ
			if (pCur == root->left)
				pParent->left = pCur->left;
			//pCur��pParent��������ʱ
			else
				pParent->right = pCur->left;
		}
		//������������Ϊ��
		else
		{
			//��������
			//����ڵ㣺����������������������������С�����������������ɾ�����֮�����Ľṹ����ı�
			//�������е������
			PNode pFirstOfIn = pCur->left;
			pParent = pCur;
			while (pFirstOfIn->right)
			{
				pParent = pFirstOfIn;
				pFirstOfIn = pFirstOfIn->right;
			}
			pCur->val = pFirstOfIn->val;//�����滻
			if (pFirstOfIn == pParent->left)
				pParent->left = pFirstOfIn->right;
			else
				pParent->right = pFirstOfIn->right;
			pCur = pFirstOfIn;

			//�������е���С���
			//PNode pLastOfIn = pCur->right;
			//while (pCur->left)
			//{
			//	pParent = pLastOfIn;
			//	pLastOfIn = pLastOfIn->left;
			//}
			//pCur->_data = pFirstOfIn->_data;//�����滻
			//if (pFirstOfIn == pParent->left)
			//	pParent->left = pFirstOfIn->left;
			//else
			//	pParent->right = pFirstOfIn->left;
			//pCur = pFirstOfIn;
		}

		delete pCur;
		//pCur = nullptr;

		return true;
#endif
	}
	//����PNode Find(const T& data)
	PNode find(const T& data)
	{
		if (root == nullptr)
			return nullptr;
		PNode temp = root;
		while (temp)
		{
			if (temp->val == data)
				break;
			else if (temp->val > data)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return temp;
	}
	//�������void InOrder()
	void InOrder()
	{
		_inorder(root);
	}
	//��СԪ��PNode LeftMost()
	PNode LeftMost()
	{
		if (root == nullptr)
			return root;
		PNode temp = root;
		while (temp->left)
			temp = temp->left;
		return temp;
	}
	//���Ԫ��PNode RightMost()
	PNode RightMost()
	{
		if (root == nullptr)
			return root;
		PNode temp = root;
		while (temp->right)
			temp = temp->right;
		return temp;
	}
	~BSTree()
	{
		_Realease(root);
	}
private:
	void _inorder(PNode _root)
	{
		if (_root)
		{
			_inorder(_root->left);
			cout << _root->val;
			_inorder(_root->right);
		}
	}
	void _Realease(PNode& _root)
	{
		if (_root)
		{
			_Realease(_root->left);
			_Realease(_root->right);
			delete _root;
		}
	}
};

int main()
{
	vector<int> arr{8,4,11,3,6,9,12,1,2,5,7,14,10};
	BSTree<int> root;
	for (auto c : arr)
		root.Insert(c);
	root.Erase(2);
	return 0;
}