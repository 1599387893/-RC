#include"BinTree.h"

//创建树
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
//拷贝一棵树
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
//前序遍历(递归)
void PosOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PosOrder(pRoot->_pLeft);
		PosOrder(pRoot->_pRight);
	}
}
//中序遍历
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}
//后序遍历(递归)
void PostOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		PosOrder(pRoot->_pLeft);
		PosOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}
//二叉树的高度
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
//是不是平衡树
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
//第K层节点个数
int GetKLevelNodeCount(BTNode* pRoot, int k)
{
	if (NULL == pRoot || k < 0)
		return 0;
	if (k == 1)
		return 1;
	return GetKLevelNodeCount(pRoot->_pLeft, k - 1) + GetKLevelNodeCount(pRoot->_pRight, k - 1);
}

//叶子节点个数
int GetLeafNodeCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	if (NULL == pRoot->_pLeft || NULL == pRoot->_pRight)
		return 1;
	return GetLeafNodeCount(pRoot->_pLeft) + GetLeafNodeCount(pRoot->_pRight);
}
//树中所有结点的个数
int GetNodeCount(BTNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	return (GetNodeCount(pRoot->_pLeft) + GetNodeCount(pRoot->_pRight) + 1);
}
//销毁树
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
//找到值为data的结点
BTNode* FindNode(BTNode* pRoot, DataType data)
{
	if (NULL == pRoot)
		return NULL;
	if (pRoot->_data == data)
		return pRoot;
	if (NULL != FindNode(pRoot->_pLeft, data))
		return FindNode(pRoot->_pLeft, data);
	return FindNode(pRoot->_pRight, data);
}
//找到某一结点的双亲结点
BTNode* GetNodeParent(BTNode* pRoot, BTNode* child)
{
	if (NULL == pRoot || NULL == child)
		return NULL;
	if (pRoot == child)
		return NULL;
	if (pRoot->_pLeft == child || pRoot->_pRight == child)
		return pRoot;
	return GetNodeParent(pRoot->_pLeft, child) || GetNodeParent(pRoot->_pRight, child);
}
//镜像树
void Mirror(BTNode* pRoot)
{
	BTNode* temp = NULL;
	if (NULL == pRoot)
		return;
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return;
	//交换左右子树
	temp = pRoot->_pLeft;
	pRoot->_pLeft = pRoot->_pRight ;
	pRoot->_pRight = temp;
	//将左右子树的左右子树交换
	Mirror(pRoot->_pLeft);
	Mirror(pRoot->_pRight);
}