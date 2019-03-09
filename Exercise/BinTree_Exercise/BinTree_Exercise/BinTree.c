#include"BinTree.h"

//������
BTNode* BuyNewNode(DataType data)
{
	BTNode* New = (BTNode*)malloc(sizeof(BTNode));
	New->_data = data;
	New->_pLeft = NULL;
	New->_pRight = NULL;
	return New;
}
BTNode* CreateBT(DataType* array, int size, int* index)
{
	BTNode* pRoot = NULL;
	if ((*index) < size && (array[*index]) != '#')
	{
		pRoot = BuyNewNode(array[*index]);
		(*index)++;
		pRoot->_pLeft = CreateBT(array, size, index);
		(*index)++;
		pRoot->_pRight = CreateBT(array, size, index);
	}
	return pRoot;
}
BTNode* CreateBinTree(DataType* array)
{
	int index = 0;
	int size = 0;
	if (array == NULL)
		return NULL;
	size = strlen(array);
	return CreateBT(array, size, &index);
}
//����һ����
BTNode* CopyBinTree(BTNode* pRoot)
{
	BTNode* CopyBT = NULL;
	CopyBT->_pLeft = NULL;
	CopyBT->_pRight = NULL;
	if (pRoot)
	{
		CopyBT->_data = pRoot->_data;
		if (pRoot->_pLeft)
			CopyBT->_pLeft = CopyBinTree(pRoot->_pLeft);
		if (pRoot->_pRight)
			CopyBT->_pRight = CopyBinTree(pRoot->_pRight);
	}
	return CopyBT;
}
//ǰ�����(�ݹ�)
void PosOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PosOrder(pRoot->_pLeft);
		PosOrder(pRoot->_pRight);
	}
}
//�������
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}
//�������(�ݹ�)
void PostOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		PosOrder(pRoot->_pLeft);
		PosOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}
//�������ĸ߶�
int BinTreeHeight(BTNode* pRoot)
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (pRoot == NULL)
		return 0;
	leftHeight = BinTreeHeight(pRoot->_pLeft);
	rightHeight = BinTreeHeight(pRoot->_pRight);
	return (leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1);
}
//�ǲ���ƽ����
int isBalanced(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 1;
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;

	return (abs(BinTreeHeight(pRoot->_pLeft) - BinTreeHeight(pRoot->_pRight)) < 2) && \
			isBalanced(pRoot->_pLeft) && \
			isBalanced(pRoot->_pRight);
}
//��K��ڵ����
int _getklevelnodecount(BTNode* pRoot, int k)
{
	if (k == 0)
		return 1;
	return (_getklevelnodecount(pRoot->_pLeft, k - 1)+_getklevelnodecount(pRoot->_pRight,k-1));
}
int GetKLevelNodeCount(BTNode* pRoot,int k)
{
	if (k < 0 || pRoot == NULL)
		return 0;
	if (k > BinTreeHeight(pRoot))
		return 0;
	if (k == 0)
		return 1;
	return (_getklevelnodecount(pRoot->_pLeft, k - 1) + _getklevelnodecount(pRoot->_pRight, k - 1));
	//return _getklevelnodecount(pRoot,k);
}
//Ҷ�ӽڵ����
int GetLeafNodeCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	if (NULL == pRoot->_pLeft || NULL == pRoot->_pRight)
		return 1;
	return GetLeafNodeCount(pRoot->_pLeft) + GetLeafNodeCount(pRoot->_pRight);
}
//�������н��ĸ���
int GetNodeCount(BTNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	return (GetNodeCount(pRoot->_pLeft) + GetNodeCount(pRoot->_pRight) + 1);
}
//������
void DestroyBinTree(BTNode** pRoot)
{	
	if (*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}