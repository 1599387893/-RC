#include"BinTree.h"

BTNode* BuyNewNode(DateTypedef data)
{
	BTNode tNew;
	tNew._data = data;
	tNew._pLeft = NULL;
	tNew._pRight = NULL;
	return &tNew;
}
BTNode* CreateBT(DateTypedef* array, int* index,int size)
{
	BTNode* NewBT;
	if (array[*index] == '#' || array[*index] == '\0' || *index > size)
		return NULL;
	NewBT = BuyNewNode(array[*index]);
	(*index)++;
	NewBT->_pLeft = CreateBT(array, index,size);
	if (NewBT->_pLeft == NULL)
		(*index)++;
	NewBT->_pRight = CreateBT(array, index,size);
	if (NewBT->_pRight == NULL)
		(*index)++;
	return NewBT;
}
void CreateBinTree(BTNode* pRoot, DateTypedef* array)
{
	assert(pRoot);
	int index = 0;
	int size = strlen(array);
	pRoot = CreateBT(array, &index,size);
}





void DestroyBinTree(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;
	//从根节点开始销毁
}
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
int isBalanced(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 1;

	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
		return 1;

	return (abs(BinTreeHeight(pRoot->_pLeft) - BinTreeHeight(pRoot->_pRight)) < 2) && isBalanced(pRoot->_pLeft) && (isBalanced(pRoot->_pRight));
}

//三种遍历方法(递归)
void PreOrder(BTNode* pRoot)
{
	assert(pRoot);
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}
void InOrder(BTNode* pRoot)
{
	assert(pRoot);
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}
void PostOrder(BTNode* pRoot)
{
	assert(pRoot);
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}
//三种遍历方法(非递归)
void PreOrderNor(BTNode* pRoot);
void InOrderNor(BTNode* pRoot);
void PostOrderNor(BTNode* pRoot);












