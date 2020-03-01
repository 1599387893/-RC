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
	BSTreeNode(int val) :val(val), left(nullptr), right(nullptr){}
};

template<class T>
class BSTree
{
	typedef struct BSTreeNode<T> BSTreeNode;
private:
	BSTreeNode* root;
public:
	BSTree()
		:root(nullptr)
	{}
	//����
	void Insert(const T& val)
	{
		if (!root)
		{
			root = new BSTreeNode(val);
			return;
		}
		BSTreeNode* node = new BSTreeNode(val);
		//���ҵ�Ҫ�����λ��
		BSTreeNode* temp = root;
		while (1)
		{
			if (temp->val < val && temp->right == nullptr)
			{
				temp->right = node;
				break;
			}
			else if (temp->val > val && temp->left == nullptr)
			{
				temp->left = node;
				break;
			}
			else if (temp->val > val)
				temp = temp->left;
			else
				temp = temp->right;
			
		}
	}
	//ɾ��
	void Erase(const T& val)
	{

	}
	//����
	//�������
	//��СԪ��
	//���Ԫ��
	~BSTree()
	{

	}
};

int main()
{
	BSTree<int> root;
	vector<int> a{ 8, 5, 1, 4, 7, 3, 2, 6, 9 };
	for (auto c : a)
		root.Insert(c);
	return 0;
}