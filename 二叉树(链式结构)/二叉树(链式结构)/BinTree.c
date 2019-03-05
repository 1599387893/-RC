#include"BinTree.h"

void CreateBinTree(BTNode* pRoot, DateTypedef* array, int size)
{
	assert(pRoot);
	while (size--)
	{
		
	}
}
//三种遍历方法
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


int TreeHeight(BTNode* pRoot)
{

}
int BinTreeHeight(BTNode* pRoot)
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (pRoot == NULL)
		return 0;
	leftHeight = TreeHeight(pRoot->_pLeft);
	rightHeight = TreeHeight(pRoot->_pRight);
	return (leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1);
}
int isBalanceTree(BTNode* pRoot)
{

}










